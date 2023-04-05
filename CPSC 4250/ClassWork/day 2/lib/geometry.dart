import 'dart:math';

// [] means an optional positional parameter
// int? means it can be null
int rectangleArea(int width, [int? height]) {
    /*if(height == null) {
        return width * width;
    }
    return width * height;*/
    // more compact alternative with the nullish coalescing operator:
    return width * (height ?? width);

}

// arrow function: if we have a single statement that just
// returns a value, use => instead of { return }
// pi is a global constant we imported from dart:math
double circleArea(double radius) => pi * radius * radius;