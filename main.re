/* Really simple node-fetch binding. */
type response;

[@bs.module]
external fetch: string => Repromise.t(response) = "node-fetch";

[@bs.send]
external text: response => Repromise.t(string) = "";



/* Download the repo's README.md and print it. */
let url =
  "https://raw.githubusercontent.com/"
  ++ "aantron/repromise-example-binding/master/README.md";

let () =
  fetch(url)
  |> Repromise.andThen(text)
  |> Repromise.wait(Js.log);
