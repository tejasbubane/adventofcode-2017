let solve = (captcha: string) => {
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
