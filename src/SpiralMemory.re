type direction =
  | Right
  | Up
  | Left
  | Down;

let _changeDir = (dir) =>
  switch dir {
  | Right => Up
  | Up => Left
  | Left => Down
  | Down => Right
  };

let _incSteps = (nextDir, currentSteps) =>
  switch nextDir {
  | Right
  | Left => currentSteps + 1
  | Up
  | Down => currentSteps
  };

let _nextCoordinates = ((x, y), dir) =>
  switch dir {
  | Right => (x + 1, y)
  | Up => (x, y + 1)
  | Left => (x - 1, y)
  | Down => (x, y - 1)
  };

let coordinates = (number) => {
  let rec coordinatesRec = (~currentNum, ~dir, ~totalSteps, ~stepsRem, ~acc) =>
    if (currentNum == number) {
      acc
    } else if (stepsRem == 0) {
      let newDir = _changeDir(dir);
      let newSteps = _incSteps(newDir, totalSteps);
      coordinatesRec(
        ~currentNum=currentNum + 1,
        ~dir=newDir,
        ~totalSteps=newSteps,
        ~stepsRem=newSteps - 1,
        ~acc=_nextCoordinates(acc, newDir)
      )
    } else {
      coordinatesRec(
        ~currentNum=currentNum + 1,
        ~dir,
        ~totalSteps,
        ~stepsRem=stepsRem - 1,
        ~acc=_nextCoordinates(acc, dir)
      )
    };
  coordinatesRec(~currentNum=1, ~dir=Right, ~totalSteps=1, ~stepsRem=1, ~acc=(0, 0))
};

let distance = (number) => {
  let (x, y) = coordinates(number);
  Js.Math.abs_int(x) + Js.Math.abs_int(y)
};
