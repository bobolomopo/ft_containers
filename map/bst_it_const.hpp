template <typename T, class KeyType, class Compare = std::less<KeyType> >
    class bst_it_const : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:
			typedef          T                                                                           value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type   difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer           pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference         reference;
            typedef ft::node<value_type>                                                                 node_type;
        public:
            node_type     *_node;
            node_type     *_root;
            node_type     *_first;
            node_type     *_last;
            Compare       _comp;
        public:
        //constructor and destructors
				
            bst_it_const(const Compare& comp = Compare()) : _node(NULL), _first(NULL), _last(NULL), _comp(comp) {};
            bst_it_const(node_type *node, const Compare& comp = Compare()) : _node(node), _root(NULL), _first(NULL), _last(NULL) , _comp(comp)
            {
                node_type  *tmp = _node;

                if (node)
                {
                    while (tmp->_parent)
                        tmp = tmp->_parent;
                    _root = tmp;
                    while (tmp->_left)
                        tmp = tmp->_left;
                    _first = tmp;
                    tmp = _root;
                    while (tmp->_right)
                        tmp = tmp->_right;
                    _last = tmp;
                }

            };
            bst_it_const(bst_it_const const &copy) : _node(copy._node), _first(copy._first), _last(copy._last), _comp(copy._comp) {};
            virtual ~bst_it_const() {};
        //operator overloads    
            bst_it_const &operator=(bst_it_const const &rhs)
            {
                this->_root = rhs._root;
                this->_node = rhs._node;
                this->_first = rhs._first;
                this->_last = rhs._last;
                this->_comp = rhs._comp;
                return (*this);
            };
            bool operator==(bst_it_const &rhs) { return (this->_node == rhs._node); };
            bool operator!=(bst_it_const &rhs) { return (this->_node != rhs._node); };
        //reference && dereference
            value_type &operator*(void) const { return (this->_node->_data); };
            value_type *operator->(void) const { return (&this->_node->_data); };
        //increments and decrements
            bst_it_const& operator++(void)
            {
                node_type *tmp;
                if (_node == _last)
                    _node++;
                else if (_node->_right)
                {
                    tmp = _node->_right;
                    while (tmp->_left)
                        tmp = tmp->_left;
                    _node = tmp;
                }
                else if (_node->_parent)
                {
                    tmp = _node->_parent;
                    while (_comp(tmp->_data.first, _node->_data.first) && tmp->_parent)
                        tmp = tmp->_parent;
                    _node = tmp;
                }
                return (*this);
            };
            bst_it_const operator++(int)
            {
                bst_it_const tmp(*this);
                operator++();
                return (tmp);
            };
            bst_it_const& operator--(void)
            {
                node_type *tmp;
                tmp = _last;
                tmp++;
                if (tmp == _node)
                {
                    _node--;
                    return (*this);
                }
                if (_node == _first)
                    return (*this);
                else if (_node->_left)
                {
                    tmp = _node->_left;
                    while (tmp->_right)
                        tmp = tmp->_right;
                    _node = tmp;
                }
                else if (tmp->_parent)
                {
                    tmp = _node->_parent;
                    while (!_comp(tmp->_data.first, _node->_data.first) && tmp->_parent)
                        tmp = tmp->_parent;
                    _node = tmp;
                }
                return (*this);
            };
            node_type *base(void) { return (this->_node); };
            bst_it_const operator--(int)
            {
                bst_it_const tmp(*this);
                operator--();
                return (tmp);
            }; 
            bst_it_const& operator-(int rhs)
            {
                while (rhs > 0)
                {
                    operator--();
                    rhs--;
                }
            }
            bst_it_const& operator+(int rhs)
            {
                while (rhs > 0)
                {
                    operator++();
                    rhs--;
                }
            }
    };