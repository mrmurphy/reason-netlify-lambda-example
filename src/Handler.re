type event = {
  .
  "path": string,
  "httpMethod": string,
  "headers": Js.Dict.t(string),
  "queryStringParameters": Js.Dict.t(string),
  "body": Js.Json.t,
  "isBase64Encoded": bool,
};

type response = {
  .
  "isBase64Encoded": bool,
  "statusCode": int,
  "headers": Js.Dict.t(string),
  "body": string,
};

type context = unit;
type complete;

type callback = (option(Js.Exn.t), option(response)) => complete;

let respondWithJson = (callback, json): complete => {
  callback(
    None,
    Some({
      "isBase64Encoded": false,
      "statusCode": 200,
      "headers": Js.Dict.fromList([("Content-Type", "application/json")]),
      "body": Js.Json.stringify(json),
    }),
  );
};

let respondWithObject = (callback, obj: Js.t('a)): complete => {
  callback(
    None,
    Some({
      "isBase64Encoded": false,
      "statusCode": 200,
      "headers": Js.Dict.fromList([("Content-Type", "application/json")]),
      "body": Js.Json.stringify(Obj.magic(obj)),
    }),
  );
};

type handler = (event, context, callback) => complete;