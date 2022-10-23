#include"raylib.h"

Camera2D CreateCamera(Vector2 _target, Vector2 _offset, float _rotation, float _zoom)
{
    Camera2D camera;
    camera.target = _target;
    camera.offset = _offset;
    camera.rotation = _rotation;
    camera.zoom = _zoom;
    
    return camera;   
}