# Ray Tracer

Let's gear up! Following the [RTv1](http://github.com/nsampre/42/tree/rtv1) project, RT takes raytracing to a new level adding the mirror effect, transparency, object cutting, textures and more! Capitalize on your RTv1 project to create an infrastructure capable of managing all the ramifications of new features. Render outstanding computer-generated imagery sure to impress! Team up with your peers and practice the unavoidable future of working with others!


## Installation

```$ git clone http://github.com/nsampre/RT && cd ./RT && make```

/!\ By ~~lazyness~~ kindness we already compiled the SDL2, SDL_TTF and SDL_IMAGE frameworks in common/frameworks. Feel free to update them directly at www.libsdl.org . Oh by the way, this product was only tested for OSX users.

## Launch and first steps

This project is client-server oriented. However, you can launch the server directly with the embeded client. To do so :

```$ ./rt_server -p 1337```

The server will be listening on port 1337, the client will be automatically launched and a 'random' map will be generated.
If you a using a nice and old macbook air and you don't want your computer to burn, you might want to launch the server only and launch the server on your brand new $10K iMac Pro 18-cores.

```$ ./rt_server -p 1337 --not-local```

The server will hang until there is at least one client connected. To launch the client on your brand new $10K iMac Pro, then just execute :

```$ ./rt_client <your macbook air address> <1337 or the port you've defined>```

Nice, but it's the $10K iMac Pro's right to show what it's computing live !

```$ ./rt_client <your macbook air address> <1337 or the port you've defined> --win``` to show a nice little live computed frame to verify everything justs works fine.


Let's just go back to this command :

```./rt_server -p 1337```

If everything works fine, you should see this :

<img src="./demo/SPLASHSCREEN.png"/>

And the '1 client connected', meaning rt_server successfully forked and launched the rt_client on background. If not... make a 🎫.

Press a key, and TADAAAAM !

<img src="./demo/LIVEEDITOR.png"/>

What ? Not sexy ? Blurry ? Weird ? It's the live edition mode. Just press enter or click on the 🎥 on the top right and wait a few seconds.

<img src="./demo/SCENESPHERE.png"/>

The first frame will always be noisy. Wait for the next frames to be added and averaged and it'll look smooth. If you like your image, you can save it by clicking on the save button [11]. It will save the image on a .png format in ./images/ and the current scene description on an .xml format in ./scenes/.

Not sexy enought ? OK. I get it. Let's make your own scene then.


## Live Scene Editor

First of all let's start from scratch with something empty.

```./rt_server -p 1337 ./scenes/void.xml```

<img src="./demo/SCENEVOID.png"/>

Let's add a sphere, click on the sphere[A] button

<img src="./demo/MENULEFT.png" width="40%"/>

<img src="./demo/SPHEREPOPPED.png"/>

The right menu popped, describing the selected object. To select an object, just click on one.

<img src="./demo/MENURIGHT.png" width="30%"/>

Just click on a field and modify it with arrow keys.

<img src="./demo/MENUTOP.png" />

Now, time for you to get some fun.

<img src="./demo/KB.png"/>


<img src="./demo/DEMO1.png"/>

<img src="./demo/DEMO2.png"/>

<img src="./demo/DEMO3.png"/>

## Diving into code

Let's talk code. I'll assume you know every bases of Ray Tracing from [RTv1](https://github.com/nsampre/42/RTv1).

Now, I am gonna dig into the heart of the path tracing technique.

- **Recursion**

```C
t_vector	compute_objects(..., t_ray RAY, ...)
{
	...

	/*
	** Let's get the closest object
	*/

	CURRENT_OBJECT = NULL;
	while (OBJECT_NODE)
	{
		...
		dist = get_distance(OBJECT_NODE, RAY);
		if (dist > 0.0)
		{	
			DIST_MAX = dist;
			CURRENT_OBJECT = OBJECT_NODE;
		}
		OBJECT_NODE = OBJECT_NODE->next;
	}

	/*
	** Assuming we hit an object,
	** let's get a ray that bounces on it
	*/	
	
	if (CURRENT_OBJECT)
		return (bounce_ray(..., CURRENT_OBJECT, RAY));
	...
}
```

```C
t_vector	bounce_ray(..., t_obj *CURRENT_OBJECT, t_ray RAY)
{
	...

	/*
	** How does the ray bounces on it ?
	** It depends on the material.
	*/

	if (CURRENT_OBJECT->reflection > 0)
	{
		return (reflection(..., RAY, CURRENT_OBJECT));
	}
	else if (CURRENT_OBJECT->refraction > 0)
	{
		return (refraction(..., RAY, CURRENT_OBJECT));
	}
	else
	{
		return (diffuse(..., RAY, CURRENT_OBJECT));
	}
}
```


- **Diffuse**

```C
t_vector	diffuse(..., t_ray ray, t_obj *CURRENT_OBJECT)
{
	...

	/*
	** The light end the recursion
	*/
	
	if (CURRENT_OBJECT->emit_light)
		return (CURRENT_OBJECT->color * CURRENT_OBJECT->light);

	/*
	** The ray bounces on the object and is randomly a little bit deviated
	*/
	
	v = CURRENT_OBJECT->point + CURRENT_OBJECT->normal + random_unit_sphere();

	/*
	** From this point a new ray is created
	*/

	NEW_RAY.ori = CURRENT_OBJECT->hit_point;
	NEW_RAY.dir = v - CURRENT_OBJECT->hit_point;

	/*
	** Let's launch it
	*/

	...

	NEXT_OBJECT_COLOR = compute_objects(..., NEW_RAY, ...);

	NEXT_OBJECT_COLOR.red   *= CURRENT_OBJECT_COLOR.red   * BOUNCE_ABSORPTION;
	NEXT_OBJECT_COLOR.green *= CURRENT_OBJECT_COLOR.green * BOUNCE_ABSORPTION;
	NEXT_OBJECT_COLOR.blue  *= CURRENT_OBJECT_COLOR.blue  * BOUNCE_ABSORPTION;
	
	...

	return (NEXT_OBJECT_COLOR);
}
```

- **Reflection**

```C
t_vector	reflection(..., t_ray RAY, t_obj *CURRENT_OBJECT)
{
	...

	NEW_RAY.dir = RAY.dir - 2.0 * CURRENT_OBJECT->normal * (RAY.dir . CURRENT_OBJECT->normal);
	NEW_RAY.ori = CURRENT_OBJECT->hit_point;
	
	...

	if ((NEW_RAY.dir . CURRENT_OBJECT->normal) > 0.0)
		NEXT_OBJECT_COLOR = compute_objects(..., NEW_RAY, ...);
	else
		NEXT_OBJECT_COLOR = CURRENT_OBJECT->color;

	...
	
	return (NEXT_OBJECT_COLOR * CURRENT_OBJECT->color);
}
```

- **Refraction**

```C
double		schlick(double cosine, double index)
{
	double r;

	r = (1.0 - index) / (double)(1 + index);
	r = r * r;
	r = (r + ((1 - r) * pow((1 - cosine), 5.0)));
	return (r);
}

t_ray		launch_ray(..., t_obj *CURRENT_OBJECT, t_vector dir, double cosine)
{
	...

	dt = vector_normalize(dir) . CURRENT_OBJECT->normal;
	discriminant = 1.0 - (ni_nt * ni_nt * (1 - (dt * dt)));
	
	if (discriminant > (double)0.0)
		reflect_probe = schlick(cosine, CURRENT_OBJECT->refraction);
	else
		reflect_probe = 1.0;
	
	if (ran_double() > reflect_probe)
	{
		NEW_RAY.dir = (dir - CURRENT_OBJECT->normal * dt * e->ni_nt) - (CURRENT_OBJECT->normal * sqrt(discriminant));
		NEW_RAY.ori = CURRENT_OBJECT->hit_point;
	}
	else
	{
		NEW_RAY.dir = dir - (CURRENT_OBJECT->normal * 2.0 * (dir . CURRENT_OBJECT->normal));
		NEW_RAY.ori = CURRENT_OBJECT->hit_point;
	}
	
	return (NEW_RAY);
}

t_vector	refraction(..., t_ray RAY, t_obj *CURRENT_OBJECT)
{
	...
	
	if (RAY.dir . CURRENT_OBJECT->normal) > 0.0)
	{
		ni_nt = CURRENT_OBJECT->refraction;
		cosine = CURRENT_OBJECT->refraction * (RAY.dir . CURRENT_OBJECT->normal) / len(RAY.dir);
	}
	else
	{
		ni_nt = 1.0 / CURRENT_OBJECT->refraction;
		cosine = -(RAY.dir . CURRENT_OBJECT->normal) / len(RAY.dir);
	}

	NEW_RAY = launch_ray(..., CURRENT_OBJECT, RAY.dir, cosine);
	
	...
	
	return (compute_objects(..., NEW_RAY, ...) * CURRENT_OBJECT->color));
}
```

Those 4 functions are the core of the project.
On top of it, you can add 
- the object detection (ray-object intersection with help of quadratic)
- color mapping, transparency mapping, skybox
- perlin noise
- ...
- and so on

## Sources

Peter Shirley's guide (do not hesitate to buy to support, it is worth it) :
- https://www.amazon.fr/Tracing-Weekend-Minibooks-Book-English-ebook/dp/B01B5AODD8/ref=sr_1_2?ie=UTF8&qid=1513645405&sr=8-2&keywords=ray+tracing
- https://www.amazon.fr/Ray-Tracing-Next-Minibooks-English-ebook/dp/B01CO7PQ8C/ref=sr_1_3?ie=UTF8&qid=1513645405&sr=8-3&keywords=ray+tracing
- https://www.amazon.fr/Ray-Tracing-Rest-Minibooks-English-ebook/dp/B01DN58P8C/ref=sr_1_1?ie=UTF8&qid=1513645405&sr=8-1&keywords=ray+tracing

Some Ray Tracing concept :
- https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing

Ray-Object intersection :
- http://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
- http://mrl.nyu.edu/~dzorin/rend05/lecture2.pdf
- https://www.cl.cam.ac.uk/teaching/1999/AGraphHCI/SMAG/node2.html

Torus :
- http://cosinekitty.com/raytrace/chapter14_set_operations.html
- http://www.ams.org/journals/mcom/1960-14-071/S0025-5718-1960-0117882-6/S0025-5718-1960-0117882-6.pdf
- http://users.wowway.com/~phkahler/torus.pdf
- https://github.com/Victor-Savu/vgt/blob/679745bb31bee728a9397e634a8b967b3db6c037/math/roots3and4.c

UV mapping :
- https://en.wikipedia.org/wiki/UV_mapping#Finding_UV_on_a_sphere
- http://www.irisa.fr/prive/kadi/Cours_LR2V/RayTracing_Texturing.pdf

A bunch of vector operation :
- https://vvvv.org/documentation/3d-vector-mathematics

Addendum, for an update :
- http://cs-people.bu.edu/sbargal/Fall%202016/lecture_notes/Dec_5_Advanced_Texture_Mapping_And_Ray_Tracing.pdf
- https://www.ics.uci.edu/~gopi/CS211B/RayTracing%20tutorial.pdf
- http://www.dcode.fr/determinant-matrice
- http://villemin.gerard.free.fr/ThNbDemo/EqaDeter.htm
- http://www.cg.info.hiroshima-cu.ac.jp/~miyazaki/knowledge/teche23.html
- https://en.wikipedia.org/wiki/Rotation_matrix#In_three_dimensions
- http://ncalculators.com/images/formulas/3x3-matrix-formula.jpg

