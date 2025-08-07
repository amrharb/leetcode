var repeatedSubstringPattern = function (s) {
  const substrings = [];
  for (let i = 0; i < s.length - 1; i++) {
    substrings.push(s.slice(0, i + 1));
  }

  for (const sub of substrings) {
    const sz = sub.length;
    if (s.length % sz !== 0) continue; // optional early prune

    let i = 0;
    let valid = true;
    while (i < s.length) {
      if (sub !== s.slice(i, i + sz)) { // <-- fixed
        valid = false;                   // <-- fixed name
        break;
      }
      i += sz;
    }
    if (valid) return true;
  }
  return false;
};
