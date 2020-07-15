#include "BasicDrawPane.h"


void BasicDrawPane::render(wxDC& dc)
{
    //dc.DrawText(wxT(_debugText), 40, 60);
    
    if (_drawResizeRectangle) {
        dc.SetPen(wxPen(wxColor(0, 0, 255), _graphThickness));
        dc.DrawRectangle(_x, _y, _resizeRectangle.x, _resizeRectangle.y);
    }
    else {
        DrawGraph(dc);
        for (auto i : _pointsToPlot) {
            PlotPoint(i, 1);
        }
        //PlotPoint(ComplexNumber(1,1));
    }
    //Get master list of vectors (nested for colors?) with complex numbers. For loop plot point them ----------------------
    
    
    
    // draw some text
    //dc.DrawText(wxT("Testing"), 40, 60);

    // draw a circle

    //dc.SetBrush(*wxGREEN_BRUSH); // green filling
    //dc.SetPen(wxPen(wxColor(255, 0, 0), 5)); // 5-pixels-thick red outline
    //dc.DrawCircle(wxPoint(200, 100), 25 /* radius */);

    // draw a rectangle
    //dc.SetBrush(*wxBLUE_BRUSH); // blue filling
    //dc.SetPen(wxPen(wxColor(255, 175, 175), 10)); // 10-pixels-thick pink outline
    //dc.DrawRectangle(300, 100, 400, 200);

    // draw a line
    //dc.SetPen(wxPen(wxColor(0, 0, 0), 3)); // black line, 3 pixels thick
    //dc.DrawLine(300, 100, 700, 300); // draw line across the rectangle

    // Look at the wxDC docs to learn how to draw other stuff

    

}
//Buttons--------

void BasicDrawPane::IncreaseGraphSizeX(wxCommandEvent& evt) { 
    _width += 10; 
    RefreshButtons();
    Refresh(); 
}
void BasicDrawPane::DecreaseGraphSizeX(wxCommandEvent& evt) {
    _width -= 10;
    RefreshButtons();
    Refresh();
}
void BasicDrawPane::IncreaseGraphSizeY(wxCommandEvent& evt) { 
    _height += 10; 
    RefreshButtons();
    Refresh(); 
}
void BasicDrawPane::DecreaseGraphSizeY(wxCommandEvent& evt) { 
    _height -= 10; 
    RefreshButtons();
    Refresh(); 
}
void BasicDrawPane::RefreshButtons() {
    btnIncreaseGraphX->SetPosition(wxPoint(_x + _width + 10, (_y + _height) / 2 - 50));
    btnDecreaseGraphX->SetPosition(wxPoint(_x + _width + 10, (_y + _height) / 2 + 30));
    btnIncreaseGraphY->SetPosition(wxPoint((_x + _width) / 2 + 20, _y + _height + 10));
    btnDecreaseGraphY->SetPosition(wxPoint((_x + _width) / 2 - 20, _y + _height + 10));

    zoomIn->SetPosition(wxPoint((_x + _width) + 10, _y + _height - 40));
    zoomOut->SetPosition(wxPoint((_x + _width) - 40, _y + _height + 10));
    MB->SetPosition(wxPoint((_x + _width) + 10, _y + _height + 10));
}
void BasicDrawPane::HideButtons() {
    btnIncreaseGraphX->Hide();
    btnDecreaseGraphX->Hide();
    btnIncreaseGraphY->Hide();
    btnDecreaseGraphY->Hide();

    zoomIn->Hide();
    zoomOut->Hide();
    MB->Hide();
}
void BasicDrawPane::UnhideButtons() {
    btnIncreaseGraphX->Show();
    btnDecreaseGraphX->Show();
    btnIncreaseGraphY->Show();
    btnDecreaseGraphY->Show();

    zoomIn->Show();
    zoomOut->Show();
    MB->Show();
}

BasicDrawPane::BasicDrawPane(wxFrame* parent) :
    wxPanel(parent)
{
    _calculator = new Calculator();

    btnIncreaseGraphX = new wxButton(this, 100, "->", wxPoint(_x + _width + 10, (_y + _height) / 2 - 50), wxSize(20, 20));
    btnDecreaseGraphX = new wxButton(this, 101, "<-", wxPoint(_x + _width + 10, (_y + _height) / 2 + 30), wxSize(20, 20));
    btnIncreaseGraphY = new wxButton(this, 102, "|\nV", wxPoint((_x + _width) / 2 + 20, _y + _height + 10), wxSize(20, 30));
    btnDecreaseGraphY = new wxButton(this, 103, "^\n|", wxPoint((_x + _width) / 2 - 20, _y + _height + 10), wxSize(20, 30));

    zoomIn = new wxButton(this, 150, "+", wxPoint((_x + _width) + 10, _y + _height - 40), wxSize(40, 40));
    zoomOut = new wxButton(this, 151, "-", wxPoint((_x + _width) - 40, _y + _height + 10), wxSize(40, 40));
    MB = new wxButton(this, 200, "MB", wxPoint((_x + _width) + 10, _y + _height + 10), wxSize(40, 40));
}

void BasicDrawPane::paintEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void BasicDrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void BasicDrawPane::DrawGraph(wxDC& evt) {
    wxClientDC dc(this);

    int axisThickness = 3;
    int gridThickness = 1;

    //border
    dc.SetPen(wxPen(wxColor(0, 0, 0), _graphThickness)); // 10-pixels-thick pink outline
    dc.DrawRectangle(_x, _y, _width, _height); //x y width height
    
    dc.SetPen(wxPen(wxColor(0, 0, 0), axisThickness)); // black line, 3 pixels thick
    //x-axis
    dc.DrawLine(_x, _y + _originY, _x + _width, _y + _originY); // draw line across the rectangle
    //y-axis
    dc.DrawLine(_x + _originX, _y, _x + _originX, _y + _height);

    //grid lines
    dc.SetPen(wxPen(wxColor(0, 0, 0), gridThickness));
    //horizontal
    for (int i = 0; (_y + _originY - (i * _graphLineSpacing)) > _y; i++) {
        dc.DrawLine(_x, _y + _originY - (i * _graphLineSpacing), _x + _width, _y + _originY - (i * _graphLineSpacing));
    }
    for (int i = 0; (_y + _originY + (i * _graphLineSpacing)) < (_y + _height); i++) {
        dc.DrawLine(_x, _y + _originY + (i * _graphLineSpacing), _x + _width, _y + _originY + (i * _graphLineSpacing));
   }
    //vertical
    for (int i = 0; (_x + _originX - (i * _graphLineSpacing)) > _x; i++) {
        dc.DrawLine(_x + _originX - (i * _graphLineSpacing), _y , _x + _originX - (i * _graphLineSpacing), _y + _height );
    }
    for (int i = 0; (_x + _originX + (i * _graphLineSpacing)) < (_x + _width); i++) {
        dc.DrawLine(_x + _originX + (i * _graphLineSpacing), _y, _x + _originX + (i * _graphLineSpacing), _y + _height);
    }
}

void BasicDrawPane::PlotPoint(int x, int y, int r) {
    wxClientDC dc(this);
    int tmpX = _originX + _x + (x * _graphLineSpacing);
    int tmpY = _originY + _y - (y * _graphLineSpacing);
    if (tmpX > _x && tmpX < _x + _width && tmpY > _y && tmpY < _y + _height) {
        dc.DrawCircle(wxPoint(tmpX, tmpY), r);
    }
}

void BasicDrawPane::PlotPoint(const ComplexNumber& c, int r) {
    wxClientDC dc(this);
    int tmpX = _originX + _x + (c.real * _graphLineSpacing);
    int tmpY = _originY + _y - (c.imaginary * _graphLineSpacing);
    if (tmpX > _x && tmpX < _x + _width && tmpY > _y && tmpY < _y + _height) {
        dc.DrawCircle(wxPoint(tmpX, tmpY), r);
    }
}

void BasicDrawPane::PlotPoint(std::tuple<ComplexNumber, int> t, int r) {
    wxClientDC dc(this);

    ComplexNumber c = std::get<0>(t);
    int depth = std::get<1>(t);
    wxColor color = _colors[depth];
    dc.SetPen(wxPen(color, _graphThickness));
    int x = _originX + _x + (c.real * _graphLineSpacing);
    int y = _originY + _y - (c.imaginary * _graphLineSpacing);
    if (x > _x && x < _x + _width && y > _y && y < _y + _height) {
        dc.DrawCircle(wxPoint(x, y), r);
    }

}


void BasicDrawPane::MouseDown(wxMouseEvent& evt) {
    _mouseDown = true;
    wxClientDC dc(this);
    wxPoint mouseLocation = evt.GetLogicalPosition(dc);

    //Resizing Graph
    if ( (abs(mouseLocation.x - (_x + _width)) < _graphResizeCorner) &&
         (abs(mouseLocation.y - (_y + _height)) < _graphResizeCorner) ){
        _isResizingGraph = true;
        _drawResizeRectangle = true;
        
    }
    else if ( (abs(mouseLocation.x - (_x + _width)) < _graphResizeCorner) &&
             !(abs(mouseLocation.y - (_y + _height)) < _graphResizeCorner)) {
        _isResizingGraphY = true;
        _drawResizeRectangle = true;
    }
    else if ( !(abs(mouseLocation.x - (_x + _width)) < _graphResizeCorner) &&
               (abs(mouseLocation.y - (_y + _height)) < _graphResizeCorner)) {
        _isResizingGraphX = true;
        _drawResizeRectangle = true;
    }
}

void BasicDrawPane::MouseUp(wxMouseEvent& evt) {
    _mouseDown = false;
    wxClientDC dc(this);
    wxPoint mouseLocation = evt.GetLogicalPosition(dc);

    //Resizing Graph
    if (_isResizingGraph) {
        _drawResizeRectangle = false;
        _isResizingGraph = false;
        SetGraphDimensions(_x, _y, mouseLocation.x - _x, mouseLocation.y - _y);
        UnhideButtons();
        RefreshButtons();
        Refresh();
    }
    else if (_isResizingGraphY) {
        _drawResizeRectangle = false;
        _isResizingGraphY = false;
        SetGraphDimensions(_x, _y, mouseLocation.x - _x, _height);
        UnhideButtons();
        RefreshButtons();
        Refresh();
    }
    else if (_isResizingGraphX) {
        _drawResizeRectangle = false;
        _isResizingGraphX = false;
        SetGraphDimensions(_x, _y, _width, mouseLocation.y - _y);
        UnhideButtons();
        RefreshButtons();
        Refresh();
    }
}

void BasicDrawPane::MouseMoved(wxMouseEvent& evt) {
    wxClientDC dc(this);
    wxPoint mouseLocation = evt.GetLogicalPosition(dc);

    if (_isResizingGraph) {
        _resizeRectangle = mouseLocation - wxPoint(_x, _y);
        HideButtons();
        Refresh();
    }
    else if (_isResizingGraphY) {
        _resizeRectangle = wxPoint( mouseLocation.x - _x, _resizeRectangle.y);
        HideButtons();
        Refresh();

    }
    else if (_isResizingGraphX) {
        _resizeRectangle = wxPoint(_resizeRectangle.x, mouseLocation.y - _y);
        HideButtons();
        Refresh();
    }
}

