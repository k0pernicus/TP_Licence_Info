package session;

import java.util.List;
import javax.persistence.EntityManager;

/**
 *  AbstractFacade class
 *  This class is abstract, to manipulate all objects which can be.
 */
public abstract class AbstractFacade<T> {
    
    /**
     * Private object Class<T>
     */
    private Class<T> entityClass;

    /**
     * Default constructor
     * @param entityClass The entity class to add as attribute
     */
    public AbstractFacade(Class<T> entityClass) {
        this.entityClass = entityClass;
    }

    /**
     * Abstract method to get the entity manager
     * @return The entityManager
     */
    protected abstract EntityManager getEntityManager();

    /**
     * Method to create an entity
     * @param entity The entity to create
     */
    public void create(T entity) {
        this.getEntityManager().persist(entity);
    }

    /**
     * Method to edit an entity
     * @param entity The entity to edit
     */
    public void edit(T entity) {
        this.getEntityManager().merge(entity);
    }

    /**
     * Method to remove an entity
     * @param entity The entity to remove
     */
    public void remove(T entity) {
        this.getEntityManager().remove(this.getEntityManager().merge(entity));
    }

    /**
     * Method to find an object in the current entity
     * @param id The object's id to find
     * @return The object designed by the id
     */
    public T find(Object id) {
        return this.getEntityManager().find(this.entityClass, id);
    }

    /**
     * Method to find all objects in the current entity
     * @return A list of objects
     */
    public List<T> findAll() {
        javax.persistence.criteria.CriteriaQuery cq = this.getEntityManager().getCriteriaBuilder().createQuery();
        cq.select(cq.from(this.entityClass));
        return this.getEntityManager().createQuery(cq).getResultList();
    }

    /**
     * Method to find all objects in the current entity
     * @param range Array of int to create the range
     * @return A list of objects ranged
     */
    public List<T> findRange(int[] range) {
        javax.persistence.criteria.CriteriaQuery cq = this.getEntityManager().getCriteriaBuilder().createQuery();
        cq.select(cq.from(this.entityClass));
        javax.persistence.Query q = this.getEntityManager().createQuery(cq);
        q.setMaxResults(range[1] - range[0] + 1);
        q.setFirstResult(range[0]);
        return q.getResultList();
    }

    /**
     * Method to count all objects in the current entity
     * @return The number of objects contains in the current entity
     */
    public int count() {
        javax.persistence.criteria.CriteriaQuery cq = getEntityManager().getCriteriaBuilder().createQuery();
        javax.persistence.criteria.Root<T> rt = cq.from(entityClass);
        cq.select(getEntityManager().getCriteriaBuilder().count(rt));
        javax.persistence.Query q = getEntityManager().createQuery(cq);
        return ((Long) q.getSingleResult()).intValue();
    }
    
}
