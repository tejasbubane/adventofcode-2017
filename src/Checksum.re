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
};

let calculate = (input) =>
  input
  |> List.fold_left(
       (sum, lst) => {
         let (min, max) = _min_max(lst);
         sum + (max - min)
       },
       0
     );
