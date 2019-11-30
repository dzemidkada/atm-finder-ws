# atm-finder-ws

# Table of contents
1. [ATM Finder WEB-service](#api)
2. [Hello world app](#hello-world)

# ATM Finder WEB-service <a name="api"></a>
High-loaded WEB-service API and implementation for High-loaded WEB-Services university subject.

The service provides a user with information about ATMs nearby.

## Representations

### ATM

ATM point of service. ATM properties:
* coordinates (**lat**, **lng**)
* some ordinary properties (**fee**[float], **cash_amount**[float], **available**[bool], **remote**[bool], **secure**[bool], etc.)

Using **HAL+GeoJSON** format a sample ATM may look like:
```{json}
{
      "type": "Feature",
      "geometry": {
        "type": "Point",
        "coordinates": [
            102.0, # lat
            0.5 # lng
        ]
      },
      "properties": {
        "fee": 0.1,
        "cash_amount": 13135.12,
        "available": "True",
        "remote": "False",
        "secure": "False"
      },
      "_links": {
        "self": {
            "href": "/service-points/atm/23"
        }
      }
    }
}
```

URL for an ATM has the following format:
`/service-points/atm/{id}`

### ATMs collection

Set of ATMs. It is either might be used to represent a set of all ATMs or just as a subset of ATMs with required properties ('a set of nearest ATMs for a particular point (user GPS coordinates)').

Collection of all ATMs has the following URL:
`/service-points/atms`

```{json}
{
      "type": "FeatureCollection",
      "features": [
        ATM-1-json-representation,
        ATM-2-json-representation,
        ...
        ATM-N-json-representation,
      ],
      "_links": {
        "self": {
            "href": "/service-points/atms"
        }
      }
    }
}
```

Response for "ATMs nearby" request is itself a resource with the following URL:
`/service-points/atms/nearest-atms?lat={lat}?lng={lng}?radius={radius}`

```{json}
{
      "type": "FeatureCollection",
      "features": [
        ATM-1-json-representation,
        ATM-2-json-representation,
        ...
        ATM-N-json-representation,
      ],
      "_links": {
        "self": {
            "href": "/service-points/atms/nearest-atms\
              ?lat={lat}\
              ?lng={lng}\
              ?radius={radius}"
        }
      }
    }
}
```

## Use cases / API

### ATM info
Method: `GET /service-points/atm/{id}`

Response: ATM representation

### ATM info update
Method: `PUT /service-points/atm/{id}`

Request: ATM representation

### List of all ATMs
Method: `GET /service-points/atms`

Response: ATMs collection representation

### List of ATMs nearby
Method: `GET /service-points/atms/nearest-atms?lat={lat}?lng={lng}?radius={radius}`

Response: ATMs collection representation

# Hello World app <a name="hello-world"></a>

## Build the server

Dockerfile: `./cppweb/cppbox/Dockerfile`.

Build an image
```{bash}
docker build -t cppbox ./cppweb/cppbox/.
```

Run a container
```{bash}
docker run -v /path/to/repo/atm-finder-ws/cppweb:/usr/src/cppweb -ti cppbox:latest bash
```

Put 'crow_all.h' (use the only release from the official Crow repo) file into the following folder:
```{bash}
/usr/src/cppweb
```

Go to the hello_world app folder and build
```{bash}
cd /usr/src/cppweb/hello_world
mkdir build && cd build
cmake ..
make
```

## Run the server

Run the container (we also specify PORT variable this time and open a port):
```{bash}
docker run -v /path/to/repo/atm-finder-ws/cppweb:/usr/src/cppweb -p 8888:8888 -e PORT=8888 cppbox:latest /usr/src/cppweb/hello_world/build/hello_world
```

## Updating the image

Run the container in the separate window:
```{bash}
docker run -ti cppbox:latest bash
```
NOTE: the is no built files or the source code from repo there!

Copy all the needed files into the container:
```{bash}
docker cp . RUNNING_CONTAINER_ID:/usr/src/cppweb
```

Commit the changes:
```{bash}
docker commit RUNNING_CONTAINER_ID hello_world:latest
```
As a result you get the app image.

You can build it using an updated Docker file using the following command:
```{bash}
docker build -t hello_world ./cppweb/hello_world/.
```
