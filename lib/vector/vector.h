#ifndef VECTOR_H
# define VECTOR_H


typedef struct  s_vector2 {
    float x;                
    float y;                
}               t_vector2;

typedef struct  s_vector3 {
    float x;                
    float y;
    float z;                
}               t_vector3;

t_vector2		vector2_lerp(t_vector2 a, t_vector2 b, float t);
t_vector2		vector2_lerp_unclamped(t_vector2 a, t_vector2 b, float t);

#endif