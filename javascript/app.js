let ar1 = [-5, 3, -12, -10, -6, 6, 12];
let ar2 = [-12, -10, -6, -3, 4, 10];
let ar3 = ar1.concat(ar2.filter((item) => ar1.indexOf(item) < 0));

ar3 = ar3.sort((a, b) => a - b);

let n = ar3.length;

if (n % 2 == 0) {
  let i = n / 2;
  console.log((ar3[i - 1] + ar3[i]) / 2);
} else {
  let i = (n + 1) / 2;
  console.log(ar3[i - 1]);
}
