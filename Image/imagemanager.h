#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <string>
#include <opencv2/opencv.hpp>

#include "Utilities/Logger/logger.h"

#define NODE_RADIUS_THICKNESS_DELTA 4
#define LINE_RADIUS_THICKNESS_DELTA 2

#define ZOOM_INIT           100
#define TRANSP_INIT         50
#define RULER_FACTOR_INIT   1.0
#define RULER_INIT          1

using namespace cv;
using namespace std;

typedef Scalar Color;
typedef std::vector<Point2d> PolygonF;

class ImageManager
{
    protected: Mat _myImage;
    protected: Mat _myDrawingLayer;

    public : const Mat& getImage() const {return _myImage;}
    public : const Mat& getDrawingLayer() const {return _myDrawingLayer;}

    private: bool _isImageOpened = false;
    public : bool isImageOpened() const noexcept {return _isImageOpened;}
    private: double _drawingLayerTransparency = TRANSP_INIT / 100.0;
    public : double getDrawingLayerTransparency() const noexcept {return _drawingLayerTransparency;}
    public : void setDrawingLayerTransparency(double val) noexcept {_drawingLayerTransparency = val;}
    private: double _zoomFactor = ZOOM_INIT / 100.0;
    public : double getZoomFactor() const noexcept {return _zoomFactor;}
    public : void zoom(double percentage);
    private: double _rulerFactor = RULER_FACTOR_INIT;
    public : double getRulerFactor() const noexcept {return _rulerFactor;}
    public : void setRulerFactor(double factor) noexcept {_rulerFactor = factor;}
    private: double _rulerLength  = RULER_INIT;
    public : double getRulerLength() const noexcept {return _rulerLength;}
    public : void setRulerLength(double length) noexcept {_rulerLength = length;}

    public : void clearDrawingLayer();

    public : void highlightCircle(
            const Point2d &p,
            const Color &col,
            int radius);

    public : void highlightLine(
            const Point2d &a,
            const Point2d &b,
            const Color &col,
            int thickness);

    public : double drawPolygon(// returns the area of polygon
            const PolygonF &polygon,
            const Color &polyEdgeCol,
            const Color &polyFillCol,
            const Color &polyTextCol,
            int thickness,
            bool drawText = true);

    public : double drawRuler(// returns the length of the ruler
            const PolygonF &ruler,
            const Color &rulerCol,
            const Color &rulerTextCol,
            int thickness,
            bool drawText = true);

    public : Mat getBlendedLayers() const;

    protected: void _onLoadImageCleanup();

    public : virtual void openImage(const Mat &image);
    public : virtual void openImage(const string &fileName);

    public : void saveImage(const string &fileName) const;

    public : ImageManager();
    public : ~ImageManager();
};

#endif // IMAGEMANAGER_H
