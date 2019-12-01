### Mongo DB setup

Get the latest image
```{bash}
docker pull mongo
```

Create a container
```{bash}
docker run -d -p 27017-27019:27017-27019 --name mongodb mongo:latest
```
