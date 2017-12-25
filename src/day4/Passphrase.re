let rec _uniqueAll = (compare, lst) =>
  switch lst {
  | [] => true
  | [_] => true
  | [hd, ...tl] =>
    switch (List.find((e) => compare(e, hd), tl)) {
    | _item =>
      /* Some statement required due to bug in bucklescript
         https://github.com/BuckleScript/bucklescript/issues/2397 */
      let _a = 1;
      false
    | exception Not_found => _uniqueAll(compare, tl)
    }
  };

let valid = (phrase, compare) =>
  phrase |> Js.String.split(" ") |> Array.to_list |> _uniqueAll(compare);

let countValid = (phrases, compare) =>
  phrases
  |> Js.String.split("\n")
  |> Array.to_list
  |> List.fold_left((acc, phrase) => valid(phrase, compare) ? acc + 1 : acc, 0);

/* Part 1 */
let compare1 = (e1, e2) => e1 == e2;

let countValid1 = (phrases) => countValid(phrases, compare1);

/* Part 2 */
let compare2 = (e1, e2) => {
  let sortedString = (str) =>
    str
    |> Js.String.split("")
    |> Array.to_list
    |> List.sort(
         (e1, e2) =>
           if (e1 == e2) {
             0
           } else if (e1 < e2) {
             (-1)
           } else {
             1
           }
       )
    |> String.concat("");
  sortedString(e1) == sortedString(e2)
};

let countValid2 = (phrases) => countValid(phrases, compare2);
