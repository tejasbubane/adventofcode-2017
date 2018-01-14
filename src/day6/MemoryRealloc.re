type state = {
  bank: string,
  iteration: int
};

let rec redistribute = (banks, index, pivot) => {
  let arrLen = Array.length(banks);
  let currPivot = pivot mod arrLen;
  if (index == currPivot || banks[index] == 0) {
    banks
  } else {
    banks[currPivot] = banks[currPivot] + 1;
    banks[index] = banks[index] - 1;
    redistribute(banks, index, currPivot + 1)
  }
};

let maxIndex = (arr) => {
  let max = ref(0);
  Array.iteri(
    (i, el) =>
      if (el > arr[max^]) {
        max := i
      },
    arr
  );
  max^
};

let stringify = (arr) => arr |> Array.map(string_of_int) |> Array.to_list |> String.concat("");

let findPrev = (acc, str) => acc |> List.find((state) => state.bank == str);

let rec iterate = (banks, currentMax, acc, iteration) => {
  let str = stringify(banks);
  switch (findPrev(acc, str)) {
  | prevState => (prevState, iteration)
  | exception Not_found =>
    let max = maxIndex(banks);
    if (max != currentMax) {
      let newAcc = [{bank: str, iteration}, ...acc];
      iterate(redistribute(banks, max, max + 1), max, newAcc, iteration + 1)
    } else {
      iterate(redistribute(banks, max, max + 1), max, acc, iteration)
    }
  }
};

let solve1 = (banks) => snd(iterate(banks, 0, [], 0));

let solve2 = (banks) => {
  let (prevState, count) = iterate(banks, 0, [], 0);
  count - prevState.iteration
};
