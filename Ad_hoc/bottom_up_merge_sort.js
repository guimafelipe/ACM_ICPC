var print = document.getElementById("print");

// print.innerText = "안녕하세요";


function ListNode(val) {
    this.val = val;
    this.next = null;
}

var print_list = function(A) {
	for (var p = A; p != null; p = p.next)
		console.log(p.val);
}

var len_list = function(A) {
	var ans = 0;

	for (var p = A; p != null; p = p.next)
		ans++;

	return ans;
}

var merge = function(A, B, tail) {
	var ans = new ListNode(0);

	var p = ans;
	while (A != null && B != null) {
		if (A.val < B.val) {
			p.next = A;
			A = A.next;
		}
		else {
			p.next = B;
			B = B.next;
		}
		p = p.next;
	}

	if (A) p.next = A;
	else if (B) p.next = B;
	
	while (p.next != null)
		p = p.next;

	tail.next = ans.next;

	return p;
}

var split = function(A, step) {
	var p = A;
	for (var i = 0; p != null && i < step - 1; i++)
		p = p.next;

	if (p == null) return null;
	var temp = p.next;
	p.next = null;

	return temp;
}

var merge_sort_bottom_up = function(A) {
	var n = len_list(A);

	if (n <= 1) return A;

	var dummy = new ListNode(0);
	dummy.next = A;

	var left;
	var right;
	for(var step = 1; step < n; step *= 2) {
		var curr = dummy.next;
		var tail = dummy;
		while (curr) {
			left = curr;
			right = split(left, step);
			curr = split(right, step);
			
			tail = merge(left, right, tail);
		}
	}

	return dummy.next;
}


var head = new ListNode(1);
head.next = new ListNode(4);
head.next.next = new ListNode(3);
head.next.next.next = new ListNode(2);
head.next.next.next.next = new ListNode(5);
head.next.next.next.next.next = new ListNode(7);
head.next.next.next.next.next.next = new ListNode(2);

head = merge_sort_bottom_up(head);

print_list(head);

// testing merge

// var A = new ListNode(1);
// A.next = new ListNode(3);
// A.next.next = new ListNode(5);

// var B = new ListNode(0);
// B.next = new ListNode(2);
// B.next.next = new ListNode(7);

// var ans = merge(A, B);
// print_list(B);

alert("Done")