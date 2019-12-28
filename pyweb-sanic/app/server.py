from sanic import Sanic
from sanic.response import json

app = Sanic()


@app.route("/hello-world")
async def hello_world(request):
    return json({"message": "Hello world!"})


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=9999, debug=False, access_log=False, log_config=None)
