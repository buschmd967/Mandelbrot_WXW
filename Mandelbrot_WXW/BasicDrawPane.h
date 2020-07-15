#pragma once

#ifndef BASICDRAWPANE_h_
#define BASICDRAWPANE_h_
#include "wx/wx.h"
#include "Calculator.h"
#include "ComplexNumber.h"
#include <vector>
#include <string>

class BasicDrawPane : public wxPanel
{
public:

    int _x = 30;
    int _y = 30;
    int _width = 400;
    int _height = 300;
    int _graphThickness = 4;
    int _graphLineSpacing = 300;
    int _graphLineSpacingDiff = 10;
    int _originX = (_width - _x) / 2;
    int _originY = (_height - _y) / 2;
    Calculator * _calculator;

    //std::vector<int> _colors = { 0 };
    
    std::vector<wxColor> _colors = { wxColor(0, 0, 0), wxColor(0, 0, 50), wxColor(0, 0, 100), wxColor(0, 0, 150), wxColor(0, 0, 200), wxColor(0, 0, 250), wxColor(0, 50, 0), wxColor(0, 50, 50), wxColor(0, 50, 100),
        wxColor(0, 50, 150), wxColor(0, 50, 200), wxColor(0, 50, 250), wxColor(0, 100, 0), wxColor(0, 100, 50), wxColor(0, 100, 100), wxColor(0, 100, 150), wxColor(0, 100, 200), wxColor(0, 100, 250), wxColor(0, 150, 0),
        wxColor(0, 150, 50), wxColor(0, 150, 100), wxColor(0, 150, 150), wxColor(0, 150, 200), wxColor(0, 150, 250), wxColor(0, 200, 0), wxColor(0, 200, 50), wxColor(0, 200, 100), wxColor(0, 200, 150), wxColor(0, 200, 200),
        wxColor(0, 200, 250), wxColor(0, 250, 0), wxColor(0, 250, 50), wxColor(0, 250, 100), wxColor(0, 250, 150), wxColor(0, 250, 200), wxColor(0, 250, 250), wxColor(50, 0, 0), wxColor(50, 0, 50), wxColor(50, 0, 100),
        wxColor(50, 0, 150), wxColor(50, 0, 200), wxColor(50, 0, 250), wxColor(50, 50, 0), wxColor(50, 50, 50), wxColor(50, 50, 100), wxColor(50, 50, 150), wxColor(50, 50, 200), wxColor(50, 50, 250), wxColor(50, 100, 0),
        wxColor(50, 100, 50), wxColor(50, 100, 100), wxColor(50, 100, 150), wxColor(50, 100, 200), wxColor(50, 100, 250), wxColor(50, 150, 0), wxColor(50, 150, 50), wxColor(50, 150, 100), wxColor(50, 150, 150),
        wxColor(50, 150, 200), wxColor(50, 150, 250), wxColor(50, 200, 0), wxColor(50, 200, 50), wxColor(50, 200, 100), wxColor(50, 200, 150), wxColor(50, 200, 200), wxColor(50, 200, 250), wxColor(50, 250, 0),
        wxColor(50, 250, 50), wxColor(50, 250, 100), wxColor(50, 250, 150), wxColor(50, 250, 200), wxColor(50, 250, 250), wxColor(100, 0, 0), wxColor(100, 0, 50), wxColor(100, 0, 100), wxColor(100, 0, 150),
        wxColor(100, 0, 200), wxColor(100, 0, 250), wxColor(100, 50, 0), wxColor(100, 50, 50), wxColor(100, 50, 100), wxColor(100, 50, 150), wxColor(100, 50, 200), wxColor(100, 50, 250), wxColor(100, 100, 0),
        wxColor(100, 100, 50), wxColor(100, 100, 100), wxColor(100, 100, 150), wxColor(100, 100, 200), wxColor(100, 100, 250), wxColor(100, 150, 0), wxColor(100, 150, 50), wxColor(100, 150, 100), wxColor(100, 150, 150),
        wxColor(100, 150, 200), wxColor(100, 150, 250), wxColor(100, 200, 0), wxColor(100, 200, 50), wxColor(100, 200, 100), wxColor(100, 200, 150), wxColor(100, 200, 200), wxColor(100, 200, 250), wxColor(100, 250, 0),
        wxColor(100, 250, 50), wxColor(100, 250, 100), wxColor(100, 250, 150), wxColor(100, 250, 200), wxColor(100, 250, 250), wxColor(150, 0, 0), wxColor(150, 0, 50), wxColor(150, 0, 100), wxColor(150, 0, 150),
        wxColor(150, 0, 200), wxColor(150, 0, 250), wxColor(150, 50, 0), wxColor(150, 50, 50), wxColor(150, 50, 100), wxColor(150, 50, 150), wxColor(150, 50, 200), wxColor(150, 50, 250), wxColor(150, 100, 0),
        wxColor(150, 100, 50), wxColor(150, 100, 100), wxColor(150, 100, 150), wxColor(150, 100, 200), wxColor(150, 100, 250), wxColor(150, 150, 0), wxColor(150, 150, 50), wxColor(150, 150, 100), wxColor(150, 150, 150),
        wxColor(150, 150, 200), wxColor(150, 150, 250), wxColor(150, 200, 0), wxColor(150, 200, 50), wxColor(150, 200, 100), wxColor(150, 200, 150), wxColor(150, 200, 200), wxColor(150, 200, 250), wxColor(150, 250, 0),
        wxColor(150, 250, 50), wxColor(150, 250, 100), wxColor(150, 250, 150), wxColor(150, 250, 200), wxColor(150, 250, 250), wxColor(200, 0, 0), wxColor(200, 0, 50), wxColor(200, 0, 100), wxColor(200, 0, 150),
        wxColor(200, 0, 200), wxColor(200, 0, 250), wxColor(200, 50, 0), wxColor(200, 50, 50), wxColor(200, 50, 100), wxColor(200, 50, 150), wxColor(200, 50, 200), wxColor(200, 50, 250), wxColor(200, 100, 0),
        wxColor(200, 100, 50), wxColor(200, 100, 100), wxColor(200, 100, 150), wxColor(200, 100, 200), wxColor(200, 100, 250), wxColor(200, 150, 0), wxColor(200, 150, 50), wxColor(200, 150, 100), wxColor(200, 150, 150),
        wxColor(200, 150, 200), wxColor(200, 150, 250), wxColor(200, 200, 0), wxColor(200, 200, 50), wxColor(200, 200, 100), wxColor(200, 200, 150), wxColor(200, 200, 200), wxColor(200, 200, 250), wxColor(200, 250, 0),
        wxColor(200, 250, 50), wxColor(200, 250, 100), wxColor(200, 250, 150), wxColor(200, 250, 200), wxColor(200, 250, 250), wxColor(250, 0, 0), wxColor(250, 0, 50), wxColor(250, 0, 100), wxColor(250, 0, 150),
        wxColor(250, 0, 200), wxColor(250, 0, 250), wxColor(250, 50, 0), wxColor(250, 50, 50), wxColor(250, 50, 100), wxColor(250, 50, 150), wxColor(250, 50, 200), wxColor(250, 50, 250), wxColor(250, 100, 0), wxColor(250, 100, 50),
        wxColor(250, 100, 100), wxColor(250, 100, 150), wxColor(250, 100, 200), wxColor(250, 100, 250), wxColor(250, 150, 0), wxColor(250, 150, 50), wxColor(250, 150, 100), wxColor(250, 150, 150), wxColor(250, 150, 200),
        wxColor(250, 150, 250), wxColor(250, 200, 0), wxColor(250, 200, 50), wxColor(250, 200, 100), wxColor(250, 200, 150), wxColor(250, 200, 200), wxColor(250, 200, 250), wxColor(250, 250, 0), wxColor(250, 250, 50),
        wxColor(250, 250, 100), wxColor(250, 250, 150), wxColor(250, 250, 200), wxColor(250, 250, 250) };

    std::vector<std::tuple<ComplexNumber, int>> _pointsToPlot;

    bool _mouseDown = false;

    int _graphResizeCorner = 10;
    bool _isResizingGraph = false;
    bool _isResizingGraphX = false;
    bool _isResizingGraphY = false;
    bool _drawResizeRectangle = false;
    wxPoint _resizeRectangle = wxPoint(_width, _height);

    wxButton* btnIncreaseGraphX = nullptr;
    wxButton* btnDecreaseGraphX = nullptr;
    wxButton* btnIncreaseGraphY = nullptr;
    wxButton* btnDecreaseGraphY = nullptr;
    wxButton* zoomIn = nullptr;
    wxButton* zoomOut = nullptr;
    wxButton* MB = nullptr;

    BasicDrawPane(wxFrame* parent);

    void paintEvent(wxPaintEvent& evt);

    void paintNow();

    void render(wxDC& dc);

    inline void SetGraphDimensions(int x, int y, int width, int height) {
        _x = x;
        _y = y;
        _width = width;
        _height = height;
        _resizeRectangle = wxPoint(_width, _height);
        _originX = (_width - _x) / 2;
        _originY = (_height - _y) / 2;
        RefreshButtons();

    }
    void IncreaseGraphSizeX(wxCommandEvent& evt);
    void DecreaseGraphSizeX(wxCommandEvent& evt);
    void IncreaseGraphSizeY(wxCommandEvent& evt);
    void DecreaseGraphSizeY(wxCommandEvent& evt);

    void MouseDown(wxMouseEvent& evt);
    void MouseUp(wxMouseEvent& evt);
    void MouseMoved(wxMouseEvent& evt);

    inline void SetGraphThickness(int thickness) { _graphThickness = thickness; }

    inline void IncreaseGridSpacing(wxCommandEvent& evt) {
        _graphLineSpacing += _graphLineSpacingDiff;
        Refresh();
    }

    inline void DecreaseGridSpacing(wxCommandEvent& evt) {
        _graphLineSpacing -= _graphLineSpacingDiff;
        Refresh();
    }
    void Test(wxCommandEvent& evt) {
        _pointsToPlot = _calculator->Mandelbrot(_colors.size(), .001, .001);
        Refresh();
    }


private:
    void PlotPoint(int x, int y, int r = 5);
    void PlotPoint(const ComplexNumber& c, int r = 5);
    void PlotPoint(std::tuple<ComplexNumber, int> t, int r = 5);
    void DrawGraph(wxDC&);
    void RefreshButtons();
    void HideButtons();
    void UnhideButtons();

    
    
    

    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */

    DECLARE_EVENT_TABLE()
};

#endif