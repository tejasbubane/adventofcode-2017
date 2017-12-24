/* Solution using immutability - with no refs as the one below */
let _solveIm = (captcha) => {
  let charList = captcha |> Js.String.split("") |> Array.to_list;
  let rec solveRec = (acc, remCaptcha) =>
    switch remCaptcha {
    | [] => acc
    | [hd] => hd == List.hd(charList) ? acc + int_of_string(hd) : acc
    | [hd, ...tl] =>
      let newAcc = hd == List.hd(tl) ? acc + int_of_string(hd) : acc;
      solveRec(newAcc, tl)
    };
  charList |> solveRec(0)
};

/* Could not come up with solution to second part without using ref :( */
let _solveMeta = (~captcha, ~interval) => {
  let chars = captcha |> Js.String.split("");
  let length = chars |> Array.length;
  let result = ref(0);
  chars
  |> Array.iteri(
       (index, num) => {
         let step = index + interval;
         let next = step >= length ? step - length : step;
         if (num == chars[next]) {
           result := result^ + int_of_string(num)
         }
       }
     );
  result^
};

let solve1 = (captcha) => _solveMeta(~captcha, ~interval=1);

let solve2 = (captcha) => _solveMeta(~captcha, ~interval=String.length(captcha) / 2);
