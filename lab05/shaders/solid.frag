#version 400
// TODO: Declare a "color" uniform (Task 10)

uniform vec3 myUniform = vec3(1.0, 1.0, 1.0);
out vec3 fragColor;

void main() {
    // TODO: Set fragColor to a color uniform. (Task 10)
    fragColor = myUniform;
}
