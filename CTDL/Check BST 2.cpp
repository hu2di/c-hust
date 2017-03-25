int checkBST(struct bnode *root)
{
	if(root->left==NULL && root->right==NULL)
		return 1;
	
	else if( (root->left==NULL) && (root->data < root->right->data) )
			return checkBST(root->right);
	
	else if( (root->left->data < root->data) && (root->right==NULL) )
		return checkBST(root->left);
	
	else if( (root->left->data < root->data) && (root->data < root->right->data) )
		{
			if(checkBST(root->left) >= checkBST(root->right))
				return 1;
		}
	else
		return 0;
}

