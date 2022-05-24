Ray Tracing is based on following the path of a ray of light through a scene as it interacts with and bounces off objects in an environment.

### Cameras:
A camera model determines how and from where the scene is being viewed,
including how an image of the scene is recorded on a sensor. 
Many rendering systems generate viewing rays starting at the camera that are then traced into the scene.

### Ray–object intersections:
We must be able to tell precisely where a given ray intersects a given geometric object. 
In addition, we need to determine certain properties of the object at the intersection point,
such as a surface normal or its material. 
Most ray tracers also have some facility for testing the intersection of a ray with multiple objects,
typically returning the closest intersection along the ray.

### Light sources:
Without lighting, there would be little point in rendering a scene. 
A ray tracer must model the distribution of light throughout the scene,
including not only the locations of the lights themselves but also the way in which they distribute their energy throughout space.

### Visibility:
In order to know whether a given light deposits energy at a point on a surface,
we must know whether there is an uninterrupted path from the point to the light source. 
Fortunately, this question is easy to answer in a ray tracer,
since we can just construct the ray from the surface to the light,
find the closest ray–object intersection, and compare the intersection distance to the light distance.

### Surface scattering:
Each object must provide a description of its appearance,
including information about how light interacts with the object’s surface, as well as the nature of the reradiated (or scattered) light. 
Models for surface scattering are typically parameterized so that they can simulate a variety of appearances.

### Indirect light transport:
Because light can arrive at a surface after bouncing off or passing through other surfaces, 
it is usually necessary to trace additional rays originating at the surface to fully capture this effect.

### Ray propagation:
We need to know what happens to the light traveling along a ray as it passes through space. 
If we are rendering a scene in a vacuum, light energy remains constant along a ray. 
Although true vacuums are unusual on Earth, they are a reasonable approximation for many environments. 
More sophisticated models are available for tracing rays through fog, smoke, the Earth’s atmosphere, and so on.

---

# Liens utiles

[Notion MiniRT](https://www.notion.so/miniRT-5f6fcdf6d05e4742b6c38f0588f12436)
[Ray Tracing in one weekend eBook](https://raytracing.github.io/)
[MiniRT Github : MartinGarciaLopez](https://github.com/martingarcialopez/miniRT)
[MiniRT Github : gmzorz](https://github.com/gmzorz/MiniRT)
[MiniRT Korean tutorial](https://velog.io/@sayi/series/miniRT)

[MiniRT Ressources : DannyFritz](https://github.com/dannyfritz/awesome-ray-tracing)
[How to Write a Ray Tracer Intuitively](https://blog.scottlogic.com/2020/03/10/raytracer-how-to.html)
[MiniRT Github : Ray Tracing in one weekend](https://github.com/RayTracing/raytracing.github.io)

[Godot Engine : Vectors maths](https://docs.godotengine.org/en/stable/tutorials/math/vector_math.html)
[Godot Engine : Vectors advanced](https://docs.godotengine.org/en/stable/tutorials/math/vectors_advanced.html)
[Computer Graphics from Scratch](https://gabrielgambetta.com/computer-graphics-from-scratch/)
[Wikipedia : Conversion between quaternions and Euler angles](https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles)
[Ray Tracer challenge : Texture Mapping](http://raytracerchallenge.com/bonus/texture-mapping.html)

[MiniRT Ressources : Viclw17](https://viclw17.github.io/)
[MiniRT Tutorial & Ressources](https://bigpel66.oopy.io/library/42/reference/5)
[Youtube : intersection d'une sphère avec une droite](https://www.youtube.com/watch?v=XA36h0EIMGY)
[Doc : Développement d'un Raytracer](https://www.alrj.org/docs/3D/raytracer/raytracertutchap1.htm)
[Edmund Optics : Comprendre la distance focale et le champ de vision](https://www.edmundoptics.fr/knowledge-center/application-notes/imaging/understanding-focal-length-and-field-of-view/)

[PDF 16 pages : Raytracing](https://euler.ac-versailles.fr/IMG/pdf/raytracing.pdf)
[Youtube : Cours 1 de Raytracing / Path-tracing](https://www.youtube.com/watch?v=1HYhrx9bzP8)
[PDF Diapo 27 pages : Transformations géométriques, rotation et translation](http://www2.ift.ulaval.ca/~pgiguere/cours/IntroRobotique2017/notes/03-VisionIII.pdf)
[FAQ Maths pour les jeux](https://jeux.developpez.com/faq/math/)
[Advanced graphics study guide](https://www.cl.cam.ac.uk/teaching/2000/AGraphHCI/AG/toplevel.html)

[Doc : Learn Computer Graphics From Scratch](https://www.scratchapixel.com/)
[PDF 32 pages++ : Le ray tracer en infographie](https://physique.cmaisonneuve.qc.ca/svezina/nyc/note_nyc/NYC_CHAP_6_IMPRIMABLE_4.pdf)