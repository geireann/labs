#version 330 core

layout(location = 0) in vec3 position;

void main() {
    gl_Position = vec4(position, 1.0);
<<<<<<< Updated upstream
=======
    // TODO: Add 0.5 to gl_Position.y (Task 2)
    //    gl_Position.y += 0.5;

    // TODO: Transform gl_Position using the model matrix uniform (Task 3)
//    gl_Position = gl_Position*model;

    // TODO: Transform the position using all three matrix uniforms. (Task 4)
    gl_Position = perspective*view*model*gl_Position;

>>>>>>> Stashed changes
}
