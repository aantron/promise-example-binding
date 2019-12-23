/* Really simple node-fetch binding. */
type response;

[@bs.module]
external fetch: string => Promise.t(response) = "node-fetch";

[@bs.send]
external text: response => Promise.t(string) = "";



/* Download the repo's README.md and print it. */
let url =
  "https://raw.githubusercontent.com/"
  ++ "aantron/promise-example-binding/master/README.md";

let () =
  fetch(url)
  ->Promise.flatMap(response => text(response))
  ->Promise.get(theText => Js.log(theText));
