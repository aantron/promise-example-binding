/* Really simple node-fetch binding. This is an adaptation of
   https://github.com/bitinn/node-fetch#plain-text-or-html:

     const fetch = require('node-fetch');

     fetch('https://github.com/')
       .then(res => res.text())
       .then(body => console.log(body));

   Except that we get the reason-promise README rather than the GitHub home
   page, and we use ReasonML to do it :) */



/* Declaration of the binding. */

type response;

[@bs.module]
external fetch: string => Promise.t(response) = "node-fetch";

[@bs.send]
external text: response => Promise.t(string) = "text";



/* User code: download the reason-promise README and print it. */

let () =
  fetch("https://raw.githubusercontent.com/aantron/promise/master/README.md")
  ->Promise.flatMap(response => text(response))
  ->Promise.get(body => Js.log(body));
