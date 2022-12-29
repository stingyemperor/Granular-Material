
flat in vec3 color;
out lowp vec4 fragmentColor;

void main() {
    vec2 point = gl_PointCoord.xy*vec2(2.0, -2.0) + vec2(-1.0, 1.0);
    float mag = dot(point, point);
    if(mag > 1.0) discard; /* outside the circle */
    fragmentColor = vec4(color, 1.0);
}
