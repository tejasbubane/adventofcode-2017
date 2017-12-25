let rec _uniqueAll = (lst) =>
  switch lst {
  | [] => true
  | [_] => true
  | [hd, ...tl] =>
    switch (List.find((e) => e == hd, tl)) {
    | _item =>
      /* Some statement required due to bug in bucklescript
         https://github.com/BuckleScript/bucklescript/issues/2397 */
      let _a = 1;
      false
    | exception Not_found => _uniqueAll(tl)
    }
  };

let valid = (phrase) => phrase |> Js.String.split(" ") |> Array.to_list |> _uniqueAll;

let countValid = (phrases) =>
  phrases
  |> Js.String.split("\n")
  |> Array.to_list
  |> List.fold_left((acc, phrase) => valid(phrase) ? acc + 1 : acc, 0);
