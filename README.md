# reason-promise example: binding to `node-fetch`

Clone this repo:

```
git clone https://github.com/aantron/promise-example-binding.git
cd promise-example-binding
```

and do:

```
npm install
npm run test
```

This will download the source code of the reason-promise `README.md` using
[reason-promise][reason-promise] and [`node-fetch`][node-fetch], and print it.
See [`main.re`][main] for the code.

[reason-promise]: https://github.com/aantron/promise
[main]: https://github.com/aantron/promise-example-binding/blob/master/main.re
[node-fetch]: https://www.npmjs.com/package/node-fetch
