module SS = Set.Make(String);

let s = ref(SS.empty);

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

let rec iterate = (banks, currentMax, acc) => {
  let str = stringify(banks);
  if (SS.mem(str, s^)) {
    acc
  } else {
    let max = maxIndex(banks);
    if (max != currentMax) {
      s := SS.add(str, s^);
      iterate(redistribute(banks, max, max + 1), max, acc + 1)
    } else {
      iterate(redistribute(banks, max, max + 1), max, acc)
    }
  }
};
