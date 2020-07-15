#pragma once

#ifndef MYAPP_h_
#define MYAPP_h_

#include "wx/wx.h"
#include "BasicDrawPane.h"


class MyApp : public wxApp
{
private:
    bool OnInit();

    wxFrame* frame;
    BasicDrawPane* drawPane;
public:



};

IMPLEMENT_APP(MyApp)

#endif

