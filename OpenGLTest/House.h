#pragma once



class Scalable
{
protected:
    float scale_X;
    float scale_Y;
public:
    void setScaleY(float scale)
    {
        this->scale_Y = scale;
    }
    void setScaleX(float scale)
    {
        this->scale_X = scale;
    }  
};


class House : public Scalable
{
private:
    struct RoofRGB
    {
        float R = 153;
        float G = 76;
        float B = 0;
    };

    struct WallRGB
    {
        float R = 255;
        float G = 229;
        float B = 204;
    };


    float min_X = 0;
    float min_Y = 0;
    float max_X = 1;
    float max_Y = 1;
    float wallCeilingY = 0.6;
    RoofRGB roofColor;
    WallRGB wallColor;
    
    void drawRoof();

    void drawWalls();

    void drawPipe();

    void drawWindow();

    void drawDoor();

public:
    void draw(float houseScale = 1)
    {
        setScaleX(houseScale);
        setScaleY(0.8);
        drawPipe();
        drawWalls();
        drawWindow();
        drawDoor();
        drawRoof();
    }

    House() = default;

    House(float minX, float minY, float maxX, float maxY, float scale = 0.6)
    {
        this->min_X = minX;
        this->min_Y = minY;
        this->max_X = maxX;
        this->max_Y = maxY;
        this->wallCeilingY = min_Y + (max_Y - min_Y) * scale;
    }
    
    void setRoofRGB(float R, float G, float B);

    void setWallsRGB(float R, float G, float B);
};

