#version 330 core

in vec2 uv;

uniform sampler2D tex;

out vec4 fragColor;

void main(){
    fragColor = vec4(1.0);

    // TODO [Task 10] Calculate the texelSize
    vec2 texelSize;
    texelSize=1.0/textureSize(tex,0).xy;

    const int supportWidth = 20;

    fragColor = vec4(0.0);
    float weights = 0.0;
    for (int i = -supportWidth; i <= supportWidth; i++) {
        float weight = (supportWidth + 1) - abs(i);
        // TODO [Task 10] Add weight * sampleColor to fragColor, where
        //               sampleColor = tex sampled at uv + the offset
        //               in the x direction (you are moving over by "i" texels)

        weights += weight;//*texture(tex,vec2((texelSize.x+i),0)+uv);
        //fragColor= fragColor+weight*texture(tex,vec2((texelSize.x+i),0)+uv);
        fragColor= fragColor+weight*texture(tex,vec2((texelSize.x*i),0)+uv);
    }
    fragColor /= weights;
}
