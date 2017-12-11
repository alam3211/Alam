#include "AlienMathWindow.h"
#include "AlienMathFrame.h"
#include <wx\arrimpl.cpp>
#include "Alien.h"
#include "Plane.h"
#include "Background.h"
#define TIMER_ID 200
WX_DEFINE_OBJARRAY(AlienObjectArray);
BEGIN_EVENT_TABLE(AlienMathWindow, wxWindow)
	EVT_TIMER(TIMER_ID, AlienMathWindow::OnTimer)
	EVT_PAINT(AlienMathWindow::OnPaint)
	EVT_KEY_DOWN(AlienMathWindow::OnKeyDown)
	EVT_KEY_UP(AlienMathWindow::OnKeyUP)
END_EVENT_TABLE()
static int count;
static int point = 0;
static int alienSpawn = 0;
static int speed=4;
static int posY;
int flag = 1;
const int pos1 = 10;
const int pos2 = 153;
const int pos3 = 296;
AlienMathWindow::AlienMathWindow(wxFrame *parent) : wxWindow(parent, wxID_ANY)
{
	wxImageHandler *jpgLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpgLoader);
	timer = new wxTimer(this, TIMER_ID);
	timer->Start(150);
	bg = new Background(0,0);
	this->player = new Plane(0,400);
	this->player->LoadPlanetBitmap();
	timer->Stop();
}

AlienMathWindow::~AlienMathWindow()
{
	timer->Stop();
	delete timer;
	delete this->player;
	delete bg;
}

void AlienMathWindow::OnPaint(wxPaintEvent & event)
{
	wxBufferedPaintDC pdc(this);
	PrepareDC(pdc);
	this->bg->Draw(pdc);
	for (int i = point*3; i < AlienArr.size(); i++) {
		if (AlienArr.Item(i) == NULL)continue;
		Alien *temp = AlienArr.Item(i);
		if (temp->alienBitmap == NULL) {
			temp->LoadAlienBitmap();
		}
		pdc.DrawBitmap(*temp->alienBitmap, wxPoint(temp->AlienGetX(), temp->AlienGetY()), true);
	}
	if (player->planeBitmap != nullptr) {
		pdc.DrawBitmap(*player->planeBitmap, wxPoint(this->player->PlaneGetX(), this->player->PlaneGetY()), true);
	}
	if (this->player->bullet != NULL && this->player->PlaneGetAmmo()==0) {
		pdc.DrawBitmap(*player->bullet->bulletBitmap, wxPoint(this->player->bullet->BulletGetX(),this->player->bullet->BulletGetY()), true);
	}
}
void AlienMathWindow::OnKeyDown(wxKeyEvent & event)
{
	if (flag == 1) {
		flag = 0;
		this->timer->Start(150);
	}
	if(event.GetKeyCode()==68){
		this->player->PlaneMove(2*speed, GetClientSize().GetWidth(), 1);
	}
	if (event.GetKeyCode() == 65) {
		this->player->PlaneMove(2*speed, GetClientSize().GetWidth(), -1);
	}
	wxMessageOutputDebug().Printf("%d", event.GetKeyCode());
	if (event.GetKeyCode() == 32 && this->player->PlaneGetAmmo()==1) {
		wxMessageOutputDebug().Printf("Shot Fired");
		this->player->PlaneShootBullet();
		this->player->bullet->LoadBulletBitmap();
	}
}

void AlienMathWindow::OnKeyUP(wxKeyEvent & event)
{
}

void AlienMathWindow::OnTimer(wxTimerEvent & event)
{
	if (this->player->bullet != NULL && this->player->PlaneGetAmmo()==0) {
		this->player->bullet->BulletMove(-15);
	}
	if (count%10 == 0) {
		wxMessageOutputDebug().Printf("Wave %d",posY);
			posY = -123 * alienSpawn;
			Alien *pertama = new Alien(pos1, posY);
			Alien *kedua = new Alien(pos2, posY);
			Alien *ketiga = new Alien(pos3, posY);
			pertama->LoadAlienBitmap();
			kedua->LoadAlienBitmap();
			ketiga->LoadAlienBitmap();
			AlienArr.Add(pertama);
			AlienArr.Add(kedua);
			AlienArr.Add(ketiga);
			pertama = NULL;
			kedua = NULL;
			ketiga = NULL;
			alienSpawn++;
	}
	wxMessageOutputDebug().Printf("%d", count++);

	for (int i = point*3; i < AlienArr.size(); i++) {
		Alien *temp = AlienArr.Item(i);
		temp->AlienMove(speed, GetClientSize().GetHeight(), 1);
		if (count % 50 == 0)speed++;
		if(this->player->bullet!=NULL){
			if (this->player->BulletIntersect(temp)) {
				this->player->PlaneReload();
				this->player->bullet->BulletSetY(721);
				point++;
				wxMessageOutputDebug().Printf("Point : %d", point);
			}
			if (this->player->bullet->BulletGetY() < 0) {
				this->player->PlaneReload();
				this->player->bullet = NULL;
				delete this->player->bullet;
			}
		}
		if (this->player->AlienIntersect(temp)) {
			timer->Stop();
		}
	}
	this->Repaint();
}

void AlienMathWindow::Repaint()
{
	this->Refresh();
	this->Update();
}
