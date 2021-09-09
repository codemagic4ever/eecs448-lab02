/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO 
		Fix this method
	*/
	return (m_size); //just returning m_size

}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO 
		Fix this method
	*/

	while(temp != nullptr)
	{
	if(temp -> getValue() == value)  //checking if the temp pointing to getValue() is equal to value
	 //if it does then the we can continue to say that isFound = true
	{
		isFound = true;
	       	//if the if condition is met then the bool isFound will be true 	
		//and we will return isFound. If the if condition is not met
		//then it will be false
		return(isFound);

	}
	temp = temp-> getNext(); //here setting temp equal to the value of temp pointing to getNext(). Getting the value by getNext()
	}
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	/** TODO 
		Fix this method
	*/
	if(!isEmpty()) //followed the method remove front as a guide
		//based on my understanding from the discussion with my TA our goal is to remove back 
		//which means that we have to traverse from start to get to the last node
		//in order to do that we are required to change the remove front in order for us to have remove back
        {

                lastNode = m_front; //here instead of temp we are setting lastNode equal to m_front
                while(lastNode -> getNext() != nullptr) //this is saying that the loop will run as long as the value is not equal to  null
		{
			secondintoLast = lastNode; //if the while condition is met we set secondintoLast equal to lastNode.
			lastNode  = lastNode->getNext(); //then the lastNode is equal to the lastNode pointing to getNext() value. 
                
		}
		delete lastNode; //here just like removeFront we will delete but instead of temp we are deleting lastNode
		secondintoLast -> setNext(nullptr); 
                m_size--; //same steps as removeFront
                isRemoved = true;
	}

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;

	}

	return(isRemoved);

}
