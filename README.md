# atm-finder-ws

# ATM Finder WEB-service
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

