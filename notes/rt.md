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