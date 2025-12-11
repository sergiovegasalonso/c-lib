# Linked List

## Applications

The following are some major applications of linked lists:

- Dynamic memory allocation — efficiently manage and allocate memory.
- Implement other data structures such as stacks, queues, and graphs.
- Represent and manipulate polynomials (each node stores a term).
- File system structures and dynamic data management in operating systems.

## Advantages

- Linked lists can grow or shrink dynamically; memory is allocated or freed as needed.
- Inserting or deleting nodes is efficient and does not require shifting elements.
- More efficient use of memory when the required size is not known in advance.
- Serve as the foundation for stacks, queues, and other complex structures.
- Allow use of non-contiguous memory blocks (helpful when memory is fragmented).

## Disadvantages

- Each node requires extra memory for one or more pointers.
- No direct index access; accessing an element requires traversal (O(N)).
- Pointer management increases implementation complexity and risk of bugs.
- Poorer cache locality compared to arrays, which can hurt performance.
- Singly linked lists do not support easy backward traversal.

# Singly Linked List

```
  HEAD
    |
    v
+---+---+    +---+---+    +---+---+    +---+---+
| 1 | o----->| 2 | o----->| 3 | o----->| 4 | o----> NULL
+---+---+    +---+---+    +---+---+    +---+---+
```

**Assumptions:** `head` is present. Where noted, a `tail` pointer is maintained; complexities that require `tail` are annotated.

## Basic Operations

<table style="width:100%;border-collapse:collapse;border:1px solid #444;margin:12px 0;">
	<thead>
		<tr>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:left;">Operation</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:left;">Operation Type</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Description</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Time Complexity</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Space Complexity</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan="3" style="background:#2b2b2b;color:#fff;padding:18px;border:1px solid #444;vertical-align:middle;font-weight:700;text-align:left;">Insertion</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At Beginning</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at the start of a linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At the End</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at the end of the linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1) with tail pointer; O(N) otherwise</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At Specific Position</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at a specific position in a linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td rowspan="3" style="background:#2b2b2b;color:#fff;padding:18px;border:1px solid #444;vertical-align:middle;font-weight:700;text-align:left;">Deletion</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">From Beginning</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node from the start of a linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">From the End</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node at the end of a linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">A Specific Node</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node from a specific position of a linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="background:#2b2b2b;color:#fff;padding:14px;border:1px solid #444;text-align:left;font-weight:700;">Traversal</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">-</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Traverse the linked list from start to end.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
	</tbody>
</table>

# Doubly Linked List

```
HEAD
  |
  v
+---+---+---+    +---+---+---+    +---+---+---+
| o | 1 | o |<-->| o | 2 | o |<-->| o | 3 | o |--> NULL
+---+---+---+    +---+---+---+    +---+---+---+
```

**Assumptions:** `head` is present. Where noted, a `tail` pointer is maintained; complexities that require `tail` are annotated.

## Basic Operations

<table style="width:100%;border-collapse:collapse;border:1px solid #444;margin:12px 0;">
	<thead>
		<tr>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:left;">Operation</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:left;">Operation Type</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Description</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Time Complexity</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Space Complexity</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan="3" style="background:#2b2b2b;color:#fff;padding:18px;border:1px solid #444;vertical-align:middle;font-weight:700;text-align:left;">Insertion</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At Beginning</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at the start of a doubly linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At the End</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at the end of the doubly linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1) with tail pointer; O(N) otherwise</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At Specific Position</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at a specific position in a doubly linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td rowspan="3" style="background:#2b2b2b;color:#fff;padding:18px;border:1px solid #444;vertical-align:middle;font-weight:700;text-align:left;">Deletion</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">From Beginning</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node from the start of a doubly linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">From the End</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node at the end of a doubly linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1) with tail pointer; O(N) otherwise</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">A Specific Node</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node from a specific position of a doubly linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="background:#2b2b2b;color:#fff;padding:14px;border:1px solid #444;text-align:left;font-weight:700;">Traversal</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">-</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Traverse the linked list from start to end or vice versa.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
	</tbody>
</table>

# Circular Linked List

```
  HEAD
    |
    v
+---+---+    +---+---+    +---+---+
| 1 | o----->| 2 | o----->| 3 | o--+
+---+---+    +---+---+    +---+---+  |
  ^                                |
  |                                |
  +--------------------------------+
```

**Assumptions:** `head` is present. Where noted, a `tail` pointer is maintained; complexities that require `tail` are annotated.

## Basic Operations

<table style="width:100%;border-collapse:collapse;border:1px solid #444;margin:12px 0;">
	<thead>
		<tr>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:left;">Operation</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:left;">Operation Type</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Description</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Time Complexity</th>
			<th style="background:#222;color:#fff;padding:14px;border:1px solid #444;text-align:center;">Space Complexity</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan="3" style="background:#2b2b2b;color:#fff;padding:18px;border:1px solid #444;vertical-align:middle;font-weight:700;text-align:left;">Insertion</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At Beginning</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at the start of a circular linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At the End</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at the end of the circular linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1) with tail pointer; O(N) otherwise</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">At Specific Position</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Insert a new node at a specific position in a circular linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td rowspan="3" style="background:#2b2b2b;color:#fff;padding:18px;border:1px solid #444;vertical-align:middle;font-weight:700;text-align:left;">Deletion</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">From Beginning</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node from the start of a circular linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">From the End</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node at the end of a circular linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="padding:12px;border:1px solid #444;text-align:left;">A Specific Node</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Delete a node from a specific position of a circular linked list.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
		<tr>
			<td style="background:#2b2b2b;color:#fff;padding:14px;border:1px solid #444;text-align:left;font-weight:700;">Traversal</td>
			<td style="padding:12px;border:1px solid #444;text-align:left;">-</td>
			<td style="padding:18px;border:1px solid #444;text-align:center;">Traverse the circular linked list (full cycle) from any node.</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(N)</td>
			<td style="padding:12px;border:1px solid #444;text-align:center;">O(1)</td>
		</tr>
	</tbody>
</table>
