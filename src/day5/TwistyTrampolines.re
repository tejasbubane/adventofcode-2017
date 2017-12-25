let calcSteps = (offsets) => {
  let rec calcStepsRec = (index, steps) =>
    switch offsets[index] {
    | exception (Invalid_argument(_)) => steps
    | item =>
      let newItem = item + 1;
      offsets[index] = newItem;
      calcStepsRec(index + item, steps + 1)
    };
  calcStepsRec(0, 0)
};
