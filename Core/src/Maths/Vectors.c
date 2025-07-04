#include "Maths/Vectors.h"
#include "Maths/Algebra.h"

#pragma region Vector2

Vector2 Vector2_Add(Vector2 vector1, Vector2 vector2)
{
    return (Vector2){vector1.x + vector2.x, vector1.y + vector2.y};
}

Vector2 Vector2_Multiply(Vector2 vector, float scalar)
{
    return (Vector2){vector.x * scalar, vector.y * scalar};
}

Vector2Int Vector2_ToInt(Vector2 vector)
{
    return (Vector2Int){(int)vector.x, (int)vector.y};
}

Vector2 Vector2_Normalized(Vector2 vector)
{
    float magnitude = Vector2_Magnitude(vector);
    if (magnitude == 0.0f)
        return (Vector2){0.0f, 0.0f};
    return Vector2_Multiply(vector, 1.0f / magnitude);
}

float Vector2_Magnitude(Vector2 vector)
{
    return SquareRoot(vector.x * vector.x + vector.y * vector.y);
}

float Vector2_Dot(Vector2 vector1, Vector2 vector2)
{
    return (vector1.x * vector2.x) + (vector1.y * vector2.y);
}

Vector2 Vector2_Lerp(Vector2 startVector, Vector2 endVector, float time)
{
    return (Vector2){
        startVector.x + (endVector.x - startVector.x) * time,
        startVector.y + (endVector.y - startVector.y) * time};
}

#pragma endregion

#pragma region Vector3

Vector3 Vector3_Add(Vector3 vector1, Vector3 vector2)
{
    return (Vector3){vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z};
}

Vector3 Vector3_Multiply(Vector3 vector, float scalar)
{
    return (Vector3){vector.x * scalar, vector.y * scalar, vector.z * scalar};
}

Vector3Int Vector3_ToInt(Vector3 vector)
{
    return (Vector3Int){(int)vector.x, (int)vector.y, (int)vector.z};
}

Vector3 Vector3_Normalized(Vector3 vector)
{
    float magnitude = Vector3_Magnitude(vector);
    if (magnitude == 0.0f)
        return (Vector3){0.0f, 0.0f, 0.0f};
    return Vector3_Multiply(vector, 1.0f / magnitude);
}

float Vector3_Magnitude(Vector3 vector)
{
    return SquareRoot(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

float Vector3_Dot(Vector3 vector1, Vector3 vector2)
{
    return (vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z);
}

Vector3 Vector3_Lerp(Vector3 startVector, Vector3 endVector, float time)
{
    return (Vector3){
        startVector.x + (endVector.x - startVector.x) * time,
        startVector.y + (endVector.y - startVector.y) * time,
        startVector.z + (endVector.z - startVector.z) * time};
}

#pragma endregion

#pragma region Vector4

Vector4 Vector4_Add(Vector4 vector1, Vector4 vector2)
{
    return (Vector4){vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z, vector1.w + vector2.w};
}

Vector4 Vector4_Multiply(Vector4 vector, float scalar)
{
    return (Vector4){vector.x * scalar, vector.y * scalar, vector.z * scalar, vector.w * scalar};
}

Vector4Int Vector4_ToInt(Vector4 vector)
{
    return (Vector4Int){(int)vector.x, (int)vector.y, (int)vector.z, (int)vector.w};
}

Vector4 Vector4_Normalized(Vector4 vector)
{
    float magnitude = Vector4_Magnitude(vector);
    if (magnitude == 0.0f)
        return (Vector4){0.0f, 0.0f, 0.0f, 0.0f};
    return Vector4_Multiply(vector, 1.0f / magnitude);
}

float Vector4_Magnitude(Vector4 vector)
{
    return SquareRoot(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
}

float Vector4_Dot(Vector4 vector1, Vector4 vector2)
{
    return (vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z) + (vector1.w * vector2.w);
}

Vector4 Vector4_Lerp(Vector4 startVector, Vector4 endVector, float time)
{
    return (Vector4){
        startVector.x + (endVector.x - startVector.x) * time,
        startVector.y + (endVector.y - startVector.y) * time,
        startVector.z + (endVector.z - startVector.z) * time,
        startVector.w + (endVector.w - startVector.w) * time};
}

#pragma endregion

#pragma region Vector2Int

Vector2Int Vector2Int_Add(Vector2Int vector1, Vector2Int vector2)
{
    return (Vector2Int){vector1.x + vector2.x, vector1.y + vector2.y};
}

Vector2Int Vector2Int_Multiply(Vector2Int vector, float scalar)
{
    return (Vector2Int){(int)(vector.x * scalar), (int)(vector.y * scalar)};
}

Vector2 Vector2_ToFloat(Vector2Int vector)
{
    return (Vector2){(float)vector.x, (float)vector.y};
}

float Vector2Int_Magnitude(Vector2Int vector)
{
    return SquareRoot((float)(vector.x * vector.x + vector.y * vector.y));
}

float Vector2Int_Dot(Vector2Int vector1, Vector2Int vector2)
{
    return (vector1.x * vector2.x) + (vector1.y * vector2.y);
}

#pragma endregion

#pragma region Vector3Int

Vector3Int Vector3Int_Add(Vector3Int vector1, Vector3Int vector2)
{
    return (Vector3Int){vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z};
}

Vector3Int Vector3Int_Multiply(Vector3Int vector, float scalar)
{
    return (Vector3Int){(int)(vector.x * scalar), (int)(vector.y * scalar), (int)(vector.z * scalar)};
}

Vector3 Vector3Int_ToFloat(Vector3Int vector)
{
    return (Vector3){(float)vector.x, (float)vector.y, (float)vector.z};
}

float Vector3Int_Magnitude(Vector3Int vector)
{
    return SquareRoot((float)(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}

float Vector3Int_Dot(Vector3Int vector1, Vector3Int vector2)
{
    return (vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z);
}

#pragma endregion

#pragma region Vector4Int

Vector4Int Vector4Int_Add(Vector4Int vector1, Vector4Int vector2)
{
    return (Vector4Int){vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z, vector1.w + vector2.w};
}

Vector4Int Vector4Int_Multiply(Vector4Int vector, float scalar)
{
    return (Vector4Int){(int)(vector.x * scalar), (int)(vector.y * scalar), (int)(vector.z * scalar), (int)(vector.w * scalar)};
}

Vector4 Vector4Int_ToFloat(Vector4Int vector)
{
    return (Vector4){(float)vector.x, (float)vector.y, (float)vector.z, (float)vector.w};
}

float Vector4Int_Magnitude(Vector4Int vector)
{
    return SquareRoot((float)(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w));
}

float Vector4Int_Dot(Vector4Int vector1, Vector4Int vector2)
{
    return (vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z) + (vector1.w * vector2.w);
}

#pragma endregion