
uniform highp mat3 viewProjectionMatrix;
uniform int numParticles;
uniform int colorMode;
uniform int screenHeight;
uniform int domainHeight;
uniform float particleRadius;
uniform vec3 uniformColor;


layout(location = 0) in highp vec2 position;
flat out vec3 color;

const vec3 colorRamp[] = vec3[] (
    vec3(1.0, 0.0, 0.0),
    vec3(1.0, 0.5, 0.0),
    vec3(1.0, 1.0, 0.0),
    vec3(1.0, 0.0, 1.0),
    vec3(0.0, 1.0, 0.0),
    vec3(0.0, 1.0, 1.0),
    vec3(0.0, 0.0, 1.0)
);

vec3 generateVertexColor() {
    if(colorMode == 1 ) { /* ramp color by particle id */
        // float segmentSize = float(numParticles)/6.0f;
        // float segment = floor(float(gl_VertexID)/segmentSize);
        // float t = (float(gl_VertexID) - segmentSize*segment)/segmentSize;
        // vec3 startVal = colorRamp[int(segment)];
        // vec3 endVal = colorRamp[int(segment) + 1];
        // return mix(startVal, endVal, t);
        return vec3(206.0f/255.0f, 162.0f/255.0f,215.0f/255.0f);
    } else { /* uniform diffuse color */
        return uniformColor;
    }
}

void main() {
    color = generateVertexColor();
    gl_PointSize = particleRadius * float(screenHeight) / float(domainHeight);
    gl_Position = mat4(viewProjectionMatrix) * vec4(position, 0, 1.0);
}
