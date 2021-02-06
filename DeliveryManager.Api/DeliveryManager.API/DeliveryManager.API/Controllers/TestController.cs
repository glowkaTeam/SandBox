using DeliveryManager.Models.Model;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DeliveryManager.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class TestController : ControllerBase
    {
        [HttpGet()]
        public ActionResult<IEnumerable<Customer>> GetCustomers()
        {
            List<Customer> customers = new List<Customer>
            {
                new Customer{ Id = 1, FirstName="Marcin", LastName = "Test" },
                new Customer{ Id = 2, FirstName="Mateusz", LastName = "Test" },
                new Customer{ Id = 3, FirstName="Kacper", LastName = "Test" }
            };

            return Ok(customers);
        }
    }
}
