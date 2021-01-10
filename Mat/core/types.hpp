#pragma once
#include "cvdef.h"
#include "interface.h"

namespace cv
{
    template<typename _Tp> class Point_
    {
    public:
        typedef _Tp value_type;

        //! default constructor
        Point_();
        Point_(_Tp _x, _Tp _y);
        Point_(const Point_& pt);
        Point_(Point_&& pt) CV_NOEXCEPT;
        Point_(const Size_<_Tp>& sz);
        Point_(const Vec<_Tp, 2>& v);

        Point_& operator = (const Point_& pt);
        Point_& operator = (Point_&& pt) CV_NOEXCEPT;
        //! conversion to another data type
        template<typename _Tp2> operator Point_<_Tp2>() const;

        //! conversion to the old-style C structures
        operator Vec<_Tp, 2>() const;

        //! dot product
        _Tp dot(const Point_& pt) const;
        //! dot product computed in double-precision arithmetics
        double ddot(const Point_& pt) const;
        //! cross-product
        double cross(const Point_& pt) const;
        //! checks whether the point is inside the specified rectangle
        bool inside(const Rect_<_Tp>& r) const;
        _Tp x; //!< x coordinate of the point
        _Tp y; //!< y coordinate of the point
    };

    typedef Point_<int> Point2i;
    typedef Point_<int64> Point2l;
    typedef Point_<float> Point2f;
    typedef Point_<double> Point2d;
    typedef Point2i Point;


    template<typename _Tp> class Size_
    {
    public:
        typedef _Tp value_type;

        //! default constructor
        Size_();
        Size_(_Tp _width, _Tp _height);
        Size_(const Size_& sz);
        Size_(Size_&& sz) CV_NOEXCEPT;
        Size_(const Point_<_Tp>& pt);

        Size_& operator = (const Size_& sz);
        Size_& operator = (Size_&& sz) CV_NOEXCEPT;
        //! the area (width*height)
        _Tp area() const;
        //! aspect ratio (width/height)
        double aspectRatio() const;
        //! true if empty
        bool empty() const;

        //! conversion of another data type.
        template<typename _Tp2> operator Size_<_Tp2>() const;

        _Tp width; //!< the width
        _Tp height; //!< the height
    };

    typedef Size_<int> Size2i;
    typedef Size_<int64> Size2l;
    typedef Size_<float> Size2f;
    typedef Size_<double> Size2d;
    typedef Size2i Size;


    class CV_EXPORTS Range
    {
    public:
        Range();
        Range(int _start, int _end);
        int size() const;
        bool empty() const;
        static Range all();

        int start, end;
    };


    template<typename _Tp> class Rect_
    {
    public:
        typedef _Tp value_type;

        //! default constructor
        Rect_();
        Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height);
        Rect_(const Rect_& r);
        Rect_(Rect_&& r) CV_NOEXCEPT;
        Rect_(const Point_<_Tp>& org, const Size_<_Tp>& sz);
        Rect_(const Point_<_Tp>& pt1, const Point_<_Tp>& pt2);

        Rect_& operator = (const Rect_& r);
        Rect_& operator = (Rect_&& r) CV_NOEXCEPT;
        //! the top-left corner
        Point_<_Tp> tl() const;
        //! the bottom-right corner
        Point_<_Tp> br() const;

        //! size (width, height) of the rectangle
        Size_<_Tp> size() const;
        //! area (width*height) of the rectangle
        _Tp area() const;
        //! true if empty
        bool empty() const;

        //! conversion to another data type
        template<typename _Tp2> operator Rect_<_Tp2>() const;

        //! checks whether the rectangle contains the point
        bool contains(const Point_<_Tp>& pt) const;

        _Tp x; //!< x coordinate of the top-left corner
        _Tp y; //!< y coordinate of the top-left corner
        _Tp width; //!< width of the rectangle
        _Tp height; //!< height of the rectangle
    };

    typedef Rect_<int> Rect2i;
    typedef Rect_<float> Rect2f;
    typedef Rect_<double> Rect2d;
    typedef Rect2i Rect;
}