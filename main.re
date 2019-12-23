/* Really simple node-fetch binding. This is an adaptation of
   https://github.com/bitinn/node-fetch#plain-text-or-html:

     const fetch = require('node-fetch');

     fetch('https://github.com/')
       .then(res => res.text())
       .then(body => console.log(body));

   Except that we get this repo's README rather than the GitHub home page, and
   we use ReasonML to do it :) */



/* Declaration of the binding. */

type response;

[@bs.module]
external fetch: string => Promise.t(response) = "node-fetch";

[@bs.send]
external text: response => Promise.t(string) = "text";



/* User code: download this repo's README and print it. */

let url =
  "https://raw.githubusercontent.com/"
  ++ "aantron/promise-example-binding/master/README.md";

let () =
  fetch(url)
  ->Promise.flatMap(response => text(response))
  ->Promise.get(theText => Js.log(theText));
