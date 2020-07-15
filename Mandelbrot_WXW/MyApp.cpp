#include "MyApp.h"

bool MyApp::OnInit()
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    frame = new wxFrame((wxFrame*)NULL, -1, wxT("Hello wxDC"), wxPoint(50, 50), wxSize(800, 600));

    drawPane = new BasicDrawPane((wxFrame*)frame);
    //btnIncreaseGraph = new wxButton(frame, 100, "test", wxPoint(100, 100), wxSize(150, 150));


    drawPane->SetGraphDimensions(10, 10, 700, 500);
    sizer->Add(drawPane, 1, wxEXPAND);

    frame->SetSizer(sizer);
    frame->SetAutoLayout(true);
    frame->Show();
    return true;
}


BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
// some useful events
/*
 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 */

 // catch paint events
    EVT_PAINT(BasicDrawPane::paintEvent)
    EVT_BUTTON(100, BasicDrawPane::IncreaseGraphSizeX)
    EVT_BUTTON(101, BasicDrawPane::DecreaseGraphSizeX)
    EVT_BUTTON(102, BasicDrawPane::IncreaseGraphSizeY)
    EVT_BUTTON(103, BasicDrawPane::DecreaseGraphSizeY)
    EVT_BUTTON(150, BasicDrawPane::IncreaseGridSpacing)
    EVT_BUTTON(151, BasicDrawPane::DecreaseGridSpacing)
    EVT_BUTTON(200, BasicDrawPane::Test)
    EVT_LEFT_DOWN(BasicDrawPane::MouseDown)
    EVT_LEFT_UP(BasicDrawPane::MouseUp)
    EVT_MOTION(BasicDrawPane::MouseMoved)

    END_EVENT_TABLE()