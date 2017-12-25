let calcSteps = (changeOffset, offsets) => {
  let rec calcStepsRec = (index, steps) =>
    switch offsets[index] {
    | exception (Invalid_argument(_)) => steps
    | offset =>
      offsets[index] = changeOffset(offset);
      calcStepsRec(index + offset, steps + 1)
    };
  calcStepsRec(0, 0)
};

/* Problem 1 */
let changeOffset1 = (item) => item + 1;

let calcSteps1 = calcSteps(changeOffset1);

/* Problem 2 */
let changeOffset2 = (item) => item >= 3 ? item - 1 : item + 1;

let calcSteps2 = calcSteps(changeOffset2);
