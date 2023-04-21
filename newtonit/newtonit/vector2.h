class Vector2d
{

public:
    double x, y;

    Vector2d operator+(Vector2d const &b)
    {
        return Vector2d{x + b.x, y + b.y};
    }

    Vector2d operator-(Vector2d const &b)
    {
        return Vector2d{x - b.x, y - b.y};
    }

    Vector2d operator*(double s)
    {
        return Vector2d{x * s, y * s};
    }

    Vector2d operator/(double s)
    {
        return Vector2d{x / s, y / s};
    }

    Vector2d &operator+=(Vector2d const &v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2d &operator-=(Vector2d const &v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector2d &operator*=(double s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vector2d &operator/=(double s)
    {
        x /= s;
        y /= s;
        return *this;
    }

    double dot( Vector2d const &b)
    {
        return x * b.x + y * b.y;
    }

    double length()
    {
        return std::sqrt(x * x + y * y);
    }

    double sqlength()
    {
        return x * x + y * y;
    }

    Vector2d normalize ()
    {
        auto const a = length();
        return *this / a;
    }
    };



std::ostream& operator<<( std::ostream& o, Vector2d const& v)
{
    o<<v.x <<"   "<<v.y;
    return o;
}

std::istream& operator>>( std::istream& i, Vector2d& v)
{
    i>>v.x;
    i>>v.y;
    return i;
}