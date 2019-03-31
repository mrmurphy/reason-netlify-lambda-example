open Handler;
let handler: handler =
  (_event, _, callback) => {
    callback->respondWithObject({"Hello": "world!"});
  };