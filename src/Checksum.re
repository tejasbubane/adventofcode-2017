let _min_max = (lst) => {
  let hd = List.hd(lst);
  lst
  |> List.fold_left(
       ((min, max), el) =>
         if (el < min) {
           (el, max)
         } else if (el > max) {
           (min, el)
         } else {
           (min, max)
         },
       (hd, hd)
     )
  |> (((min, max)) => max - min)
};

/* Find in list any element(el) such that num and el are fully divisible */
let rec _division = (lst) =>
  switch lst {
  /* Returning 0 from base case will not add anything to result
     Although we can assume that there will always be some two numbers
     perfectly divisble, handling the edge-case where
     code should not break at runtime */
  | [] => 0
  | [_hd] => 0
  | [hd, ...tl] =>
    switch (tl |> List.find((e) => hd mod e == 0 || e mod hd == 0)) {
    | div => div < hd ? hd / div : div / hd
    | exception Not_found => _division(tl)
    }
  };

let _calculate = (~input, ~rowOp) => input |> List.fold_left((sum, lst) => sum + rowOp(lst), 0);

let calculateFirst = (input) => _calculate(~input, ~rowOp=_min_max);

let calculateSecond = (input) => _calculate(~input, ~rowOp=_division);
