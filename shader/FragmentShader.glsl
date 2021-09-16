#version 330 core

// Interpolated values from the vertex shaders
in vec3 v_color;
in vec3 v_normal;
in vec3 v_view;

// Ouput data
out vec4 frag_color;

//// parameter for phong shader
uniform vec3 Ka,Ks,Ke;
uniform vec3 Sa,Ss,Sd;
uniform vec3 lightdir;
uniform float sh;



void main(){
//
//    vec3 normal =  normalize(v_normal);
//    vec3 view = normalize(v_view);
//    vec3 light=normalize(lightdir);
//
//    //    vec3 matdiffuse=texture(diffuse_map,v_texcoord).rgb;
//    vec3 diff=max(dot(normal,light),0.0)*Sd*v_color;
//
//    vec3 refl=2.0*normal*dot(normal,light)-light;
//    vec3 spec=pow(max(dot(refl,v_view),0),sh)*Ss*Ks;
//
//    vec3 ambi=Ka*Sa;

    frag_color=vec4(0.9,0.2,0.1,1.0);

    //frag_color=vec4(diff+spec+ambi+Ke,1.0);

}