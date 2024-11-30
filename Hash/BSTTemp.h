template<typename T, typename CompareLessThan, typename CompareGreaterThan, typename CompareEqualTo>
class BST {
	struct Node {
		T data;
		Node* left;
		Node* right;

		Node(const T value) {
			data = value;
			left = nullptr;
			right = nullptr;
		}
	};

	Node* root;
	CompareLessThan lessThan;
	CompareGreaterThan greaterThan;
	CompareEqualTo equalTo;

	public:
		BST(CompareLessThan lt, CompareGreaterThan gt, CompareEqualTo eq) {
			root = nullptr;
			lessThan = lt;
			greaterThan = gt;
			equalTo = eq;
		}

		void insert(const T& value) {
			root = insert(root, value);
		}

		Node* insert(Node* root, const T& value) {
			if (root == nullptr) {
				return new Node(value);
			}
			if (lessThan(value, root->data)) {
				root->left = insert(root->left, value);
			}
			else {
				root->right = insert(root->right, value);
			}
			return root;
		}

		bool search(const T& value) const {
			return search(root, value);
		}

		bool search(Node* root, const T& value) const {
			if (root == nullptr) {
				cout << "Player not found" << endl;
				return false;
			}
			else if (equalTo(value, root->data) {
				cout << "Player found" << endl;
				return true;
			}
			else if (lessThan(value, root->data)) {
				return search(root->left, value);
			}
			else {
				return search(root->right, value);
			}
		}



	
};