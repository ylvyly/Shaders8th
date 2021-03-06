varying vec3 normal, position;
 

void main()
{ 
 
 vec3 lightDir = normalize(vec3(gl_LightSource[0].position)); 
 vec3 posNormal = normalize(position);
 vec3 reflectVec = normalize(-reflect(lightDir, normal));
 
 vec4 ambient = gl_LightSource[0].ambient * gl_FrontMaterial.ambient;
 vec4 diffuse = gl_LightSource[0].diffuse * max(dot(normal,lightDir),0.0) * gl_FrontMaterial.diffuse;
 vec4 specular = gl_FrontMaterial.specular * pow(max(dot(reflectVec, posNormal), 0.0), gl_FrontMaterial.shininess);
 
 gl_FragColor = ambient + diffuse + specular;
 gl_FragColor.a = 1.0;


}